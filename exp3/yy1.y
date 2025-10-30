%{
  #include<stdio.h>
  //#include "y.tab.c"
  #include<stdlib.h>
  int yylex();
  void yyerror(const char*s);

%}
%token IDENTIFIER NUMBER INVALID NEWLINE
%%
input: IDENTIFIER NEWLINE { printf("valid identifier"); exit(0);}
     | INVALID NEWLINE   { yyerror("invalid identifier");}
     ;
      
%%
void yyerror(const char*s){
  printf("invalid identifier\n");
  exit(1);
}
int main()
{
  printf("enter identifier:");
  yyparse();
  return 0;
}

