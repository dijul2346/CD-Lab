%{
    #include "y.tab.h"
    #include<stdlib.h>
%}

%%
[0-9]+ {yylval = atoi(yytext); return NUMBER;}
\n  {return NEWLINE;}
[\t] ; 
"+"	return '+';
"-"	return '-';
"*"	return '*';
"/"	return '/';
"("	return '(';
")"	return ')';

%%
int yywrap()
{
   return 1;
}