%{
#include <stdio.h>
#include "attr.h"
int yylex();
void yyerror(char * s);
#include "symtab.h"
%}

%union {tokentype token; 

boolean_constant: true
				| false
				;
          }

%token PROG PERIOD VAR ARRAY RANGE OF
%token INT WRITELN THEN ELSE IF 
%token BEG END ASG
%token EQ NEQ LT LEQ OR EXOR AND NOT TRUE FALSE
%token WHILE DO FOR BOOLEAN INTEGER
%token <token> ID ICONST 

%start program

%nonassoc EQ NEQ LT LEQ
%left '+' '-' OR EXOR
%left '*' AND 
%right NOT

%nonassoc THEN
%nonassoc ELSE

%%
program : PROG ID ';' block PERIOD { printf("\n\n     Done with compiling program %s\n", $2.str);}
	;

block	: variables cmpdstmt
	;

variables: VAR vardcls
		 | ;
		 ;

vardcls: vardcls vardcl ';' | vardcl ';'
	   ;

vardcl: idlist : type
	  ;

idlist: idlist ',' ID
	  | ID
	  ;

type: ARRAY '[' ICONST ".." ICONST ']' OF stype
	| stype
	;

stype: INTEGER
	 | BOOLEAN
	 ;

stmtlist : stmtlist ';' stmt 
	| stmt              
	;

stmt: ifstmt
	| astmt
	| wstmt
	| fstmt
	| cmpdstmt
	| writestmt
	;

wstmt: WHILE condexp DO stmt
	 ;

fstmt: FOR ID ":=" ICONST ',' ICONST DO astmt
	;

ifstmt: ifhead THEN stmt ELSE stmt 
	  | ifhead THEN stmt
	  ;

ifhead: IF condexp
	  ;

cmpdstmt: BEG stmtlist END
	;

writestmt: WRITELN '(' exp ')'
		 ;

astmt : lvalue ":=" exp                 
	;

exp	: rvalue
	| exp '+' exp		{ }
	| exp '-' exp		{ }
	| exp '*' exp		{ }
	| exp AND exp		{ }
	| exp OR exp		{ }
	| exp EXOR exp		{ }
	| NOT exp		{ }
	| '(' exp ')'		{ }
	| ICONST                { } 
	;

condexp: exp "!=" exp
	   | exp "==" exp
	   | exp "<" exp
	   | exp "<=" exp
	   | ID
	   | boolean_constant
	;

lvalue: ID 
	  | ID '[' exp ']'
	  ;

rvalue: ID
	  | ID '[' exp ']'
	  ;

constant: ICONST 
		| boolean_constant
		;

boolean_constant: TRUE
				| FALSE
				;

%%

void yyerror(char* s) {
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

