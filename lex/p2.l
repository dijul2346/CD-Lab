%{
    #include<stdio.h>
    #include<stdlib.h>
%}

%%
"void"|"main"|"int"|"float"|"if"|"else"|"while" {printf("%s - Keyword\n",yytext);}
[0-9]+ {printf("%s -Digit\n",yytext);}
[a-zA-Z][_a-zA-Z0-9]* {printf("%s - Variable\n",yytext);}
[#a-zA-Z<>.]+ {printf("%s - Preprocessors\n",yytext);}
[<|>|=|!|+|-|*|/]+ {printf("%s - Operator\n",yytext);}
[(|)|{|}|,|;] {printf("%s - Punctuators\n", yytext);}
[ \t\n] ;
. ;
%%

int main(){
    yyin=fopen("input.c","r");
    yylex();
    return 0;
}

int yywrap(){
    return 1;
}