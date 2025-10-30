%{
    #include<stdio.h>
    #include<stdlib.h>
    int yylex();
    void yyerror(const char *s);
%}

%token NUMBER IDENTIFIER NEWLINE
%left '+''-'
%left '*''/''%'
%nonassoc UMINUS

%%
input:
    |input expr NEWLINE {printf("result : %d\n",$2); exit(0);}
    |input NEWLINE
    ;

expr:
    expr '+' expr   {$$ = $1 + $3;}
    |expr '-' expr  {$$ = $1 - $3;}
    |expr '*' expr  {$$ = $1 - $3;}
    |expr '/' expr  {if($3==0){
        yyerror("division by zero");
				exit(1);}
                $$ = $1 - $3;}
    |'(' expr ')'		{ $$ = $2; }
	| '-' expr %prec UMINUS { $$ = -$2; }
	|NUMBER		{ $$ = $1;}
	;

%%
void yyerror(const char* s)
{
   printf("invalid expression");
   exit(1);
}
int main()
{
   printf("simple calculator\n enter expression:");
   yyparse();
   return 0;
}