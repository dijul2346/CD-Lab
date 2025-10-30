%{
    #include<stdlib.h>
    #include<stdio.h>
    #include "calc.tab.h"
%}

%%

[0-9]+ {yylval =atoi(yytext);return NUMBER;}
[\n]    {return EOL;}
[ \t]    ;
.       {return yytext[0];}

%%
int yywrap(){
    return 1;
}