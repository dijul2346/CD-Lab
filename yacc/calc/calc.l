%{
    #include "calc.tab.h"
    #include<stdio.h>
%}

%%
[0-9]+ {yylval.num = atoi(yytext);return NUMBER;}
[+\-*/()] {return yytext[0];}
\n {return '\n';}
[ \t] ;
. { printf("Invalid character: %s\n", yytext); }
%%

int yywrap(void) {
    return 1;
}