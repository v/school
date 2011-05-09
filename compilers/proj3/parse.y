%{
#include <stdio.h>
#include "attr.h"
#include "instrutil.h"
int yylex();
void yyerror(char * s);
#include "symtab.h"
#include "deptest.h"

FILE *outfile;
char *CommentBuffer;
 
%}

%union {tokentype token;
        regInfo targetReg;
		struct { int trueLabel; int falseLabel; int endLabel; } label;
        }

%token PROG PERIOD VAR 
%token INT BOOL ARRAY RANGE OF WRITELN THEN IF 
%token BEG END ASG DO FOR
%token EQ NEQ LT LEQ 
%token AND OR XOR NOT TRUE FALSE 
%token ELSE
%token WHILE BOOLEAN
%token EXOR
%token <token> ID ICONST 

%type <token> constant boolean_constant stype tail type lvalue

%type <targetReg> exp condexp

%type <label> ifhead ifstmt

%start program

%nonassoc EQ NEQ LT LEQ 
%left '+' '-'  OR EXOR
%left '*' AND
%right NOT

%nonassoc THEN
%nonassoc ELSE

%%
program : {emitComment("Assign STATIC_AREA_ADDRESS to register \"r0\"");
           emit(NOLABEL, LOADI, STATIC_AREA_ADDRESS, 0, EMPTY); } 
           PROG ID ';' block PERIOD { }
	;

block	: variables cmpdstmt { }
	;

variables: /* empty */
	| VAR vardcls { }
	;

vardcls	: vardcls vardcl ';' { }
	| vardcl ';' { }
	| error ';' { yyerror("***Error: illegal variable declaration\n");}  
	;

vardcl	: ID tail { insert($1.str, $2.type, NextOffset());  }
	;

tail	: ',' ID tail { insert($2.str, $3.type, NextOffset()); $$.type = $3.type; }
	| ':' type { $$.type = $2.type; }
	;

type: ARRAY '[' ICONST RANGE ICONST ']' OF stype  { $$.type = mystrcat("arr-", $8.type); }
	| stype { $$.type = $1.type; }
	;

stype: INT { $$.type = "int";  } 
	 | BOOLEAN { $$.type = "bool"; } 
	 ;

stmtlist : stmtlist ';' stmt { }
		| stmt { }
        | error { yyerror("***Error: illegal statement \n");}
	;

stmt    : ifstmt { }
	| wstmt { }
	| fstmt { }
	| astmt { }
	| writestmt { }
	| cmpdstmt { }
	;

cmpdstmt: { load_regs(); } BEG stmtlist END { clear_regs(); }
	;

ifstmt :  ifhead THEN stmt { emit($1.falseLabel, NOP, 0, 0, 0); emitComment("This is the \"false\" branch"); } 
        | ifhead THEN stmt ELSE { int endLabel = NextLabel(); emit(BR, endLabel, 0, 0, 0); emit($1.falseLabel, NOP, 0, 0, 0); $1.endLabel = endLabel; } 
          stmt { emit(BR, $1.endLabel, 0, 0, 0); emit($1.endLabel, NOP, 0, 0, 0); }
	;

ifhead : IF condexp { 
		   int trueLabel = NextLabel();
		   int falseLabel = NextLabel();
		   emit(NOLABEL, CBR, $2.targetRegister, trueLabel, falseLabel);
		   emitComment("This is the \"true\" branch"); 
		   emit(trueLabel, NOP, 0, 0, 0);
		   $$.falseLabel = falseLabel;
		   $$.trueLabel = trueLabel;
		 }
        ;

writestmt: WRITELN '(' exp ')' { emit(NOLABEL, STORE, $3.targetRegister, 0, 0); emit(NOLABEL, OUTPUT, 1024, 0, 0); }
	;

wstmt	: WHILE  { emitComment("Control code for \"WHILE DO\"");}
          condexp { emitComment("Body of \"WHILE\" construct starts here");}
          DO stmt  { }
	;


fstmt : FOR ID ASG ICONST ',' ICONST DO astmt { }
	;

astmt : lvalue ASG exp { set_reg($1.str, $3.targetRegister); }
	;

lvalue	: ID { $$.str = $1.str; }
        |  ID '[' exp ']' { }
        ;

exp	: exp '+' exp		{ int newReg = NextRegister();
                                  $$.targetRegister = newReg;
                                  emit(NOLABEL, 
                                       ADD, 
                                       $1.targetRegister, 
                                       $3.targetRegister, 
                                       newReg);
                                }

        | exp '-' exp		{ int newReg = NextRegister(); 
                                  $$.targetRegister = newReg;
                                  emit(NOLABEL, 
                                       SUB, 
                                       $1.targetRegister, 
                                       $3.targetRegister, 
                                       newReg);
                                }

	| exp '*' exp		{ int newReg = NextRegister(); 
                                  $$.targetRegister = newReg;
                                  emit(NOLABEL, 
                                       MULT, 
                                       $1.targetRegister, 
                                       $3.targetRegister, 
                                       newReg);
                                }
	| exp AND exp		{
		int newReg = NextRegister();
		$$.targetRegister = newReg;
		emit(NOLABEL, L_AND, $1.targetRegister, $3.targetRegister, newReg);
	}
	| exp OR exp		{ 	
		int newReg = NextRegister();
		$$.targetRegister = newReg;
		emit(NOLABEL, L_OR, $1.targetRegister, $3.targetRegister, newReg);
	}
	| exp EXOR exp		{
		int newReg = NextRegister();
		$$.targetRegister = newReg;
		emit(NOLABEL, L_XOR, $1.targetRegister, $3.targetRegister, newReg);
	}
	| '(' exp ')'		{ $$.targetRegister = $2.targetRegister; }	

        | ID			{ $$.targetRegister = get_reg($1.str); }

        | ID '[' exp ']'	{ }


	| constant                { int newReg = NextRegister();
	                          $$.targetRegister = newReg;
	                          emit(NOLABEL, LOADI, $1.num, newReg, EMPTY); }

	| error { yyerror("***Error: illegal expression\n");}  
	;

condexp	: exp NEQ exp		{  
		int newReg = NextRegister();
		$$.targetRegister = newReg;
		emit(NOLABEL, CMPNE, $1.targetRegister, $3.targetRegister, newReg);
	}
	| exp EQ exp	{
		int newReg = NextRegister();
		$$.targetRegister = newReg;
		emit(NOLABEL, CMPEQ, $1.targetRegister, $3.targetRegister, newReg);
	}
	| exp LT exp	{
		int newReg = NextRegister();
		$$.targetRegister = newReg;
		emit(NOLABEL, CMPLT, $1.targetRegister, $3.targetRegister, newReg);
	}
	| exp LEQ exp	{
		int newReg = NextRegister();
		$$.targetRegister = newReg;
		emit(NOLABEL, CMPLE, $1.targetRegister, $3.targetRegister, newReg);
	}
	| error { yyerror("***Error: illegal conditional expression\n");}  
        ;

constant: ICONST  { $$.num = $1.num; $$.type = strdup("int");  }
		| boolean_constant { $$.num = $1.num; $$.type = strdup("bool");  }
		;

boolean_constant: TRUE { $$.num = 1; }
				| FALSE { $$.num = 0; }
				;

%%

void yyerror(char* s) {
        fprintf(stderr,"%s\n",s);
	fflush(stderr);
        }

int
main() {
  printf("\n          CS415 Spring 2011\n        Vectorizing Compiler\n");
  printf("    Version 1.0, Wednesday, April 20 \n\n");
  
  outfile = fopen("iloc.out", "w");
  if (outfile == NULL) { 
    printf("ERROR: cannot open output file \"iloc.out\".\n");
    return -1;
  }

  CommentBuffer = (char *) malloc(500);  

  printf("1\t");
  yyparse();
  printf("\n");
  
  /*** START: THIS IS BOGUS AND NEEDS TO BE REMOVED ***/    
  /*

  emitComment("LOTS MORE BOGUS CODE");
  emit(1, NOP, EMPTY, EMPTY, EMPTY);
  emit(NOLABEL, VECTON, EMPTY, EMPTY, EMPTY);
  emit(NOLABEL, LOADI, 12, 1, EMPTY);
  emit(NOLABEL, LOADI, 1024, 2, EMPTY);
  emit(NOLABEL, STORE, 1, 2, EMPTY);
  emit(NOLABEL, OUTPUT, 1024, EMPTY, EMPTY);
  emit(NOLABEL, LOADI, -5, 3, EMPTY);
  emit(NOLABEL, CMPLT, 1, 3, 4);
  emit(NOLABEL, VECTOFF, EMPTY, EMPTY, EMPTY);
  emit(NOLABEL, STORE, 4, 2, EMPTY);
  emit(NOLABEL, OUTPUT, 1024, EMPTY, EMPTY);
  emit(NOLABEL, CBR, 4, 1, 2);
  emit(2, NOP, EMPTY, EMPTY, EMPTY);

*/

  /*** END: THIS IS BOGUS AND NEEDS TO BE REMOVED ***/    

  fclose(outfile);
  
  return 1;
}




