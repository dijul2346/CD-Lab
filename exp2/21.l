%{
    #include<stdio.h>
    int lines=0,words=0,chars=0;
%}
%%
\n {lines++;}
[a-zA-Z0-9]+ {words++;chars+=yyleng;}
.;
%%

int main(){
    yyin=fopen("data.txt","r");
    yylex();
    printf("No. of lines: %d\n",lines); 
    printf("No. of words: %d\n",words); 
    printf("No. of characters: %d\n",chars); 
    return 0; 
}
int yywrap(void) 
{ 
return 1; 
} 