%{
    #include "y.tab.h"
    #include<stdio.h>
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
%%
int yywrap(void) {
    return 1;
}