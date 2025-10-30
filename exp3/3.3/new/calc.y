%{
    #include<stdio.h>
    #include<stdlib.h>
    int yylex();
    void yyerror(const char *s);
    
%}

%token NUMBER
%token EOL
%left '+''-'
%left '*''/'

%%
exprs:
    | exprs expr EOL {printf("= %d\n",$2);}
    ;

expr:
    NUMBER
    | expr '+' expr {$$ = $1 + $3;}
    | expr '-' expr {$$ = $1 - $3;}
    | expr '*' expr {$$ = $1 * $3;}
    | expr '/' expr {$$ = $1 / $3;}
    ;
%%

void yyerror(const char *s) {
    printf("Error: %s\n", s);
}

int main(){
    printf("Enter arithemetic expression\n");
    yyparse();
    return 0;
}