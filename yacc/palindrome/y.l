%{
    #include<stdio.h>
    #include<string.h>
    #include "y.tab.h"
%}


%%
[a-z]+ {yylval.str = strdup(yytext);return STRING;}
[ \t\n] ;
. ;

%%
int yywrap(void) { return 1; }