%{
  #include<stdlib.h>
  #include "calc.tab.h"
%}
%%
[0-9]+ {yylval = atoi(yytext); return NUMBER;}
\n  {return NEWLINE;}
[\t] ; {/*ignore whitespace*/}
"+"	return '+';
"-"	return '-';
"*"	return '*';
"/"	return '/';
"("	return '(';
")"	return ')';
. {yyerror("Invalid character"); exit(1);}
%%
int yywrap()
{
   return 1;
}