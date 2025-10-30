%{
    #include<stdio.h>
    #include<stdlib.h>
    int yylex();
    void yyerror(const char *s);
%}

%token NUMBER ID
%left '+' '-'
%left '*' '/'

%%
stmt: expr {printf("Valid expression");return 0;}

expr:expr '+' expr
    |expr '-' expr
    |expr '*' expr
    |expr '/' expr
    |ID
    |NUMBER
    ;

%%

void yyerror(const char *s) {
    printf("Invalid arithmetic expression\n");
}

int main() {
    printf("Enter an arithmetic expression: ");
    yyparse();
    return 0;
}

