%{
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>

    int yylex(void);
    void yyerror(const char *s);
%}

%union {
    char *str;
}

%token <str> STRING
%type  <str> input

%%
input:
    STRING {
        int len = strlen($1);
        int i,flag =1;
        for(i=0;i<len/2;i++){
            if($1[i] != $1[len - i -1]){
                flag=0;
                break;
            }
        }
        if(flag)
            printf("Palindrome\n");
        else
            printf("Not Palindrome\n");
        free($1);
    }
    ;
%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main(void) {
    return yyparse();
}
