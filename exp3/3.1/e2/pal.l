%{
#include <stdio.h>
#include <string.h>

%}
%%

[a-zA-Z]+ { 
    char str[100];
    strcpy(str,yytext);
    int len=strlen(str);
    int flag=1;
    for(int i=0;i<len;i++){
        if(str[i] != str[len-i-1]){
            flag=0;
            break;
        }
    }
    if (flag)
        printf("%s - Palindrome\n", str);
    else
        printf("%s - Not a Palindrome\n", str);
}
[ \t\n]+ ;
. ;

%%

int main(){
    printf("Enter a word");
    yylex();
    return 0;
}

int yywrap(){
    return 1;
}