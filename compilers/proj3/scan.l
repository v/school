%{
#include <string.h>
#include "attr.h"
#include "parse.tab.h"
#define YY_SKIP_YYWRAP
%}
	extern YYSTYPE yylval;
        extern int yywrap() {return 1;};
	extern int isatty();
	int lines = 1;

D       [0-9]
id	[A-Za-z][A-Za-z0-9]*

%%
{D}+		{ECHO;
		yylval.token.num = atoi(yytext);
		return(ICONST);}
:=		{ECHO;return(ASG);}
"=="		{ECHO;return(EQ);}
"!="		{ECHO;return(NEQ);}
"<="		{ECHO;return(LEQ);}
"<"		{ECHO;return(LT);}
".."            {ECHO;return(RANGE);}
\.		{ECHO;return(PERIOD);}
"/*"		{
		int c1 = 0; int c2 = input();
		ECHO;
		for(;;) {
			if (c2 == EOF) {
				printf("ERROR: EOF detected in comment\n");
				yyterminate();
				}
			fprintf(yyout,"%c",c2);
			if (c1 == '*' && c2== '/') break;
			c1 = c2;
			c2 = input();
			if (c1 == '\n' && c2 != EOF)
				{lines++; fprintf(yyout,"%d\t",lines);}
			}
		}
[\[\]*+(),:;=-]	{ECHO;return(yytext[0]);}
program		{ECHO;return(PROG);}
begin		{ECHO;return(BEG);}
var		{ECHO;return(VAR);}
integer		{ECHO;return(INT);}
boolean		{ECHO;return(BOOL);}
array		{ECHO;return(ARRAY);}
of		{ECHO;return(OF);}
while		{ECHO;return(WHILE);}
do		{ECHO;return(DO);}
end		{ECHO;return(END);}
for		{ECHO;return(FOR);}
if		{ECHO;return(IF);}
then		{ECHO;return(THEN);}
else		{ECHO;return(ELSE);}
writeln		{ECHO;return(WRITELN);}
and		{ECHO;return(AND);}
or		{ECHO;return(OR);}
xor		{ECHO;return(XOR);}
not		{ECHO;return(NOT);}
true		{ECHO;return(TRUE);}
false		{ECHO;return(FALSE);}
{id}		{ECHO;
		yylval.token.str = (char *) malloc(strlen(yytext)+1);
		strcpy(yylval.token.str,yytext);
		return(ID);
		}
\n		{int c;
		ECHO;
		c = input();
		if (c != EOF) {unput(c); lines++; fprintf(yyout,"%d\t",lines);}
		else yyterminate();
		}
[ \t]		{ECHO;}
[!@#$%^&|?]	{ECHO;
		printf("\nERROR: %c is an illegal character\n",yytext[0]);
		}
%%
