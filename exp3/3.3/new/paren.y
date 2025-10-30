%{
#include <stdio.h>
void yyerror(const char *s);
int yylex(void);
%}

%%
S : '(' S ')' S
  | /* empty */
  ;
%%

void yyerror(const char *s) {
    printf("Invalid parentheses\n");
}

int main() {
    printf("Enter parentheses string: ");
    if(yyparse() == 0)
        printf("Balanced parentheses\n");
    return 0;
}
