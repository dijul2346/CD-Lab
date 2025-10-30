%{
    #include<stdio.h>
    #include<unistd.h>
    int lines=0,words=0,c=0;
%}

%%
[a-zA-Z0-9] {c++;}
[a-zA-Z0-9]+ {words++;}
[\n] {lines++;}
[ \t] ;
. ;

%%

int main(){
    yyin=fopen("input.c","r");
    yylex();
    printf("Chars : %d\nLines : %d \nWords %d",c,lines,words);
    return 0;
}

int yywrap(){
    return 1;
}