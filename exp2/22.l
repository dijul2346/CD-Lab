%{
#include<stdio.h>    
%}
%%

"void"|"main"|"int"|"float"|"if"|"else"|"for" {printf("%s - Keyword\n",yytext);}
[0-9]+ {printf("%s - Digit",yytext);}
[a-zA-Z][_a-zA-Z0-9]* {printf("%s -Identifier\n",yytext);}
.

%%
int main(){
    yyin=fopen("data.txt","r");
    yylex();
    return 0;
}
int yywrap(void){
    return 1;
}