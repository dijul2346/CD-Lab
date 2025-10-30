%{
    #include<stdio.h>
    #include<stdlib.h>
    yylex();
    void yyerror(const char *s);
%}

%token NUMBER IDENTIFIER
%left '+','-'
%left '*''/''%'
%nonassoc UMINUS
%%
ArithmeticExpression:
    expr({printf("valid expression");}exit(0);)
    ;
expr:
    expr '+' expr
    |expr '-' expr
    |expr '*' expr
	|expr '/' expr
	|expr '%' expr
    |'(' expr ')'
	| '-' expr %prec UMINUS
	|NUMBER
	|IDENTIFIER
	;
%%
void yyerror(const char* s)
{
   printf("invalid expression");
   exit(1);
}
int main(){
    printf("enter expression);
    yyparse();
    return 0;
}