%{
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    int yylex(void);
    void yyerror(const char *s);
%}

%union{
    char* sval;
}

%token <sval> word

%%

check : 
    word {
        int left=0;
        int right=strlen($1)-1;

        while(left<= right){
            if($1[left] == $1[right]);
            else{
                printf("Not Palindrome ");
                exit(1);
            }
            left++;
            right--;
        }
        printf("Palindrome");
    }

%%

int main(){
    printf("Enter a string : ");
    yyparse();
    return 0;
}


void yyerror(const char *s){
    exit(1);
}

