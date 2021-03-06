%{
#include <stdio.h>
#include "attr.h"
int yylex();
void yyerror(char * s);
void bool_check(char *a, char *b, char *op);
void int_check(char *a, char *b, char *op);
void same_check(char *a, char *b, char *op);

void emit(char *instr, char *a, char *b, char *c);

int is_array(char *type);


#include "symtab.h"
%}

%union { attributes attrs;
		strlist *slist;
		  }

%token PROG PERIOD VAR ARRAY RANGE OF
%token INT WRITELN THEN ELSE IF 
%token BEG END ASG
%token EQ NEQ LT LEQ OR EXOR AND NOT TRUE FALSE
%token WHILE DO FOR BOOLEAN
%token ID ICONST 

%type <attrs> BOOLEAN ID_USE ID ICONST TRUE FALSE VAR ARRAY RANGE constant lvalue rvalue type stype exp condexp
%type <slist> idlist

%start program

%nonassoc EQ NEQ LT LEQ
%left '+' '-' OR EXOR
%left '*' AND 
%right NOT

%nonassoc THEN
%nonassoc ELSE

%%
program : PROG ID ';' block PERIOD { printf("\n\n     Done with compiling program %s\n", $2.token.str); }
		;

block	: variables cmpdstmt
	  ;

variables: VAR vardcls
		 | ;
		 ;

vardcls: vardcls vardcl ';' 
	   | vardcl ';'
	   | error delim { yyerror("\n***Error: illegal variable declaration\n"); }
	   ;

vardcl: idlist ':' type { 
	 	  char *type = $3.type;
		  if(!type)
			  type = strdup("error");

		  char *duplicate = strlist_map($1, insert, $3.type);
		  if(duplicate)
		  {
			char buffer[1024];
			sprintf(buffer, "\n***Error: duplicate declaration of %s\n", duplicate);
			yyerror(buffer);
		  }
	  }
	  ;

idlist: idlist ',' ID { strlist_insert($1, $3.token.str); $$ = $1}
	  | ID { strlist *s = malloc(sizeof(strlist)); strlist_new(s); strlist_insert(s, $1.token.str); $$ = s; }
	  ;

type: ARRAY '[' ICONST RANGE ICONST ']' OF stype 
	{
		if($3.token.num > $5.token.num)
			yyerror("\n***Error: lower bound exceeds upper bound\n");
		$$.type = mystrcat("arr-", $8.type);
	}
	| stype { 
		char *type = $1.type;
		if(!type)
			type = strdup("error");
		$$.type = type;
	}
	;

stype: INT { $$.type = strdup("int"); } 
	 | BOOLEAN { $$.type = strdup("bool"); } 
	 ;

stmtlist : stmtlist ';' stmt 
		 | stmt              
		 | error stmt_end { yyerror("\n***Error: illegal statement\n"); }
	;

stmt_end: constant 
	| rvalue 
	| '\n'
	;

stmt: ifstmt
	| astmt
	| wstmt
	| fstmt
	| cmpdstmt
	| writestmt
	;

delim: ';'
	 | '\n';

wstmt: WHILE condexp DO stmt
	 | error delim { yyerror("\n*** Error: illegal conditional expression\n"); }
	 ;

fstmt: FOR ID_USE ASG constant ',' constant DO astmt {
		if(!$4.type || strcmp("int", $4.type))
		{
			yyerror("\n***Error: lower bound not integer constant\n");
		}
		if(!$6.type || strcmp("int", $6.type))
		{
			yyerror("\n***Error: upper bound not integer constant\n");
		}

		if(($4.type && !strcmp("int", $4.type)) && ($6.type && !strcmp("int", $6.type)) && $4.token.num > $6.token.num)
			yyerror("\n***Error: lower bound exceeds upper bound\n");

		if(!$2.type || strcmp($2.type, "int"))
			yyerror("\n***Error: induction variable not scalar integer variable\n");
	 }
	 ;

ifstmt: ifhead THEN stmt ELSE stmt 
	  | ifhead THEN stmt
	  ;

ifhead: IF condexp
	  | error delim { yyerror("\n*** Error: illegal conditional expression\n"); }
	  ;

cmpdstmt: BEG stmtlist END
		;

writestmt: WRITELN '(' exp ')' {
			if(!$3.type || strcmp($3.type, "int"))
				yyerror("\n***Error: illegal type for write\n");
		 } ;

astmt : lvalue ASG exp  { 
		if(!$1.type || !$3.type || strcmp($1.type, $3.type))
			yyerror("\n***Error: assignment types do not match\n");
		if($1.type && is_array($1.type))
			yyerror("\n***Error: assignment to whole array\n");
	  }
	  ;

exp	: rvalue { if(!$1.type) { $1.type = strdup("error");} $$.type = $1.type; }
	| exp '+' exp		{ int_check($1.type, $3.type, "+"); $$.type = $1.type; }
	| exp '-' exp		{ int_check($1.type, $3.type, "-"); $$.type = $1.type; }
	| exp '*' exp		{ int_check($1.type, $3.type, "*"); $$.type = $1.type; }
	
	| exp AND exp		{ bool_check($1.type, $3.type, "and"); $$.type = $1.type; }
	| exp OR exp		{ bool_check($1.type, $3.type, "or"); $$.type = $1.type;}
	| exp EXOR exp		{ bool_check($1.type, $3.type, "exor"); $$.type = $1.type;}
	| NOT exp			{ bool_check($2.type, $2.type, "not"); $$.type = $2.type;}
	| '(' exp ')'		{ $$.type = $2.type; }
	| constant          { if(!$1.type) { $1.type = strdup("error"); } $$.type = $1.type;  } 
	| error stmt_end { yyerror("\n***Error: illegal expression\n"); $$.type = strdup("error"); }
	;

condexp: exp NEQ exp	{ same_check($1.type, $3.type, "!="); $$.type = $1.type; }
	   | exp EQ exp 	{ same_check($1.type, $3.type, "=="); $$.type = $1.type; }
	   | exp LT exp 	{ same_check($1.type, $3.type, "<"); $$.type = $1.type; }
	   | exp LEQ exp 	{ same_check($1.type, $3.type, "<="); $$.type = $1.type; }
	   | ID_USE 			{ 
	   		if(!$1.type)
				$1.type = strdup("error");
			if(strcmp($1.type, "bool"))
				yyerror("\n***Error: exp in if stmt must be boolean\n");
				
			$$.type = $1.type;
		}
	   | boolean_constant  { $$.type = strdup("bool"); }
	;

lvalue: ID_USE { 
		  char *type = lookup($1.token.str); 
		  if(!type)
		  	type = strdup("error");
		  $$.type = type;
	  }
	  | ID_USE '[' exp ']' {
			if(!is_array(lookup($1.token.str)))
			{
				char buffer[1024];
				sprintf(buffer, "\n***Error: id %s is not an array\n", $1.token.str);
				yyerror(buffer);
				$$.type = strdup("error");
			}
			else
				$$.type = (char *)(lookup($1.token.str) + 4); 

			if(!$3.token.str)
				$3.token.str = strdup("error");
			char *type = lookup($3.token.str);

			if(!type || strcmp(type, "int"))
				yyerror("\n***Error: subscript exp not type integer\n");

		}
	  ;

rvalue: ID_USE { 
			char *type = lookup($1.token.str);
			if(!type)
				type = strdup("error");

			$$.type = type;

		} 
	  | ID_USE '[' exp ']' {
	  		if(!is_array(lookup($1.token.str))) { 
				char buffer[1024];
				sprintf(buffer, "\n***Error: id %s is not an array\n", $1.token.str);
				yyerror(buffer);
				$$.type = strdup("error");
			} else {  
				$$.type = strdup(lookup($1.token.str)+4);
			} 
		}
	  ;

constant: ICONST  { $$.type = strdup("int"); }
		| boolean_constant { $$.type = strdup("bool"); }
		;

boolean_constant: TRUE
				| FALSE
				;
ID_USE: ID { 

	  		if(!$1.token.str)
				$1.token.str = strdup("error");

			char *type = lookup($1.token.str);
			if (!type)
			{
				char buffer[1024];
				sprintf(buffer, "\n***Error: undeclared identifier %s\n", $1.token.str);
				yyerror(buffer);
				type = strdup("error");
			}
			$$.type = type;
			$$.token.str = $1.token.str;
		}
	  ;

%%

void yyerror(char* s) {
		//we ran into a bug. Stop type checking.
		fprintf(stderr,"%s\n",s);
		}

int
main() {
	printf("\n     CS415 Front-End Compiler\n");
	printf("      Project 2, Spring 2011\n\n");
	printf("1\t");
	yyparse();
	return 1;
}

void int_check(char *a, char *b, char *op)
{
	if(strcmp(a, b) || strcmp(a, "int"))
	{
		char buffer[1024];
		sprintf(buffer, "\n***Error: types of operands for operation %s do not match\n", op);
		yyerror(buffer);
	}
}

void bool_check(char *a, char *b, char *op)
{
	if(strcmp(a, b) || strcmp(a, "bool"))
	{
		char buffer[1024];
		sprintf(buffer, "\n***Error: types of operands for operation %s do not match\n", op);
		yyerror(buffer);
	}
}

void same_check(char *a, char *b, char *op)
{
	if(strcmp(a, b))
	{
		char buffer[1024];
		sprintf(buffer, "\n***Error: types of operands for operation %s do not match\n", op);
		yyerror(buffer);
	}
}

int is_array(char *type)
{
	if(!type)
		return 0;
	return starts_with(type, "arr");
}
	
void emit(char *instr, char *a, char *b, char *c)
{
	fprintf(stdout, "%s \t %s, %s => %s \n", instr, a, b, c);
}

void emit_2(char *instr, char *a, char *b)
{
	fprintf(stdout, "%s \t %s => %s \n", instr, a, b);
}
