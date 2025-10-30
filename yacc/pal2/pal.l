%{
    #include<stdio.h>
    #include<string.h>
    #include "y.tab.h"
%}

%%
[a-z]+ {yylval.sval =yytext; return word;}
[\n] {return 0;}
[ \t] ;
. {return yytext[0];}
%%

int yywrap(){
    return 1;
}