%{
    #include<stdio.h>
    #include<string.h>
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
    if(flag)
        printf("Palindrome");
    
    else
        printf("Not Palindrome");
    
}
[ \t\n]+ ;
. ;

%%

int main(){
    printf("Enter a word ");
    yylex();
    return 0;
}

int yywrap(){
    return 1;
}