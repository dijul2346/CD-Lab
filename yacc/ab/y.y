%{
    #include<stdio.h>
    #include<stdlib.h>

    int yylex(void);
    void yyerror(const char *s);
%}

%%

input:
    string '\n' {printf("Valid string of form a^n b^n\n");}
    | '\n' {}
    ;

string:
    'a' 'b'
    | 'a' string 'b'
    ;

%%

void yyerror(const char *s){
    printf("Invalid string");
}

int main(void){
    yyparse();
    return 0;
}