%{
    #include <stdio.h>
    #include<stdlib.h>
    int yylex();
    void yyerror(const char *s);
%}

%token IDENTIFIER NUMBER INVALID NEWLINE

%%

input: IDENTIFIER NEWLINE {printf("Valid identifier\n");exit(0);}
    | INVALID NEWLINE {yyerror("invalid identifier\n");exit(1);}
    ;

%%
void yyerror(const char *s){
    printf("invalid identifier\n");
    exit(0);
}

int main(){
    printf("Enter identifier :");
    yyparse();
    return 0;
}