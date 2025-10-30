%{
    #include<stdio.h>
    int yylex();
    void yyerror(const char *s);
%}

%token NEWLINE NUMBER IDENTIFIER
%left '+' '-'
%left '*' '\\'
%nonassoc UMINUS

%%
input : input expr NEWLINE {printf("Sum : %d",$2);}
        | NEWLINE {}
    
    expr: expr '+' expr {$$ = $1 + $2}
        | expr '-' expr {$$ = $1 - $2}
        | expr '*' expr {$$ = $1 * $2}
        | expr '\\' expr {$$ = $1 / $2}
        ;
%%

int main(void){
    printf("Enter a n arithmetic expression : ");
    yyparse();
    return 0;
}

void yyerror(const char *s){
    fprintf("Invalid");
}