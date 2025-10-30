#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include <stdbool.h>

char keywords[][10] = {"int", "main", "return"};
char operators[] = "+-*/=<>"; 
char separators[] = ",(){};";

bool isKeyword(char *word) {
    for (int i = 0; i < 3; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return true;
    }
    return false;
}

bool isOperator(char c) {
    for (int i = 0; operators[i] != '\0'; i++) {
        if (operators[i] == c)
            return true;
    }
    return false;
}

bool isSeparator(char c) {
    for (int i = 0; separators[i] != '\0'; i++) {
        if (separators[i] == c)
            return true;
    }
    return false;
}

int main(){
    FILE *f=fopen("input.c","r");
    if(!f){
        printf("Cannot Open File \n");
        return 1;
    }

    freopen("output.txt","w",stdout);

    char c,token[50],pd[50];
    int i;

    while((c=fgetc(f)) !=EOF){
        if(isspace(c))
            continue;
            
        if(c == '#'){
            printf("( # - Preprocessor Directive)\n");
            while((c=fgetc(f))!='\n' && c != EOF){
                putchar(c);
            }
        }
        else if (isOperator(c)) {
            if (c == '=') printf("(=, Assignment)\n");
            else printf("(%c, Operator)\n", c);
        }

        // Separator
        else if (isSeparator(c)) {
            printf("(%c, Separator)\n", c);
        }

        else if(isalpha(c) || c == '_'){
            i=0;
            while(isalnum(c)||c=='_'){
                token[i++]=c;
                ungetc(c,f);

                if (isKeyword(token))
                    printf("(%s, Keyword)\n", token);
                else
                printf("(%s, Identifier)\n", token);
            }
        }

    }
}