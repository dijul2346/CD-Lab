%{#include<stdio.h>
%}

%%

[a-zA-Z._%+]+@[a-zA-Z0-9.-]+\.[A-Za-z]{2,} { printf("Valid Email: %s\n", yytext); }
.|\n                                               { printf("Invalid Email: %s\n", yytext); }

%%

int yywrap() { return 1; }

int main() {
    printf("Enter an email address: ");
    yylex();
    return 0;
}