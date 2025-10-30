%{
  #include<stdio.h>
  #include<stdlib.h>
  int yylex();
  void yyerror(const char*s);
%}
%token A B NEWLINE INVALID
%%
input:string NEWLINE	{printf("Valid string");exit(0);}
      |INVALID NEWLINE	{printf("Invalid string");exit(0);}
      ;
string:A string B
	|/*empty*/
	;
%%
void yyerror(const char*s)
{
   printf("invalid expression\n");
   exit(1);
}

int main()
{
   printf("Enter the string (a followed by equal no: of b):");
   yyparse();
   return 0;
}
