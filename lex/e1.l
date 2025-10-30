%{
    #include<stdio.h>  
    #include<string.h>  
    int flag=1;
%}

%%
[0-1]+ {
    int c=0;
    int n=strlen(yytext);
    for(int i=0;i<n;i++){
        if(yytext[i]=='0'){
            c++;
        }
    }
    if(c>3){
        flag=0;
    }
}
[2-9a-zA-Z]+ {flag=0;}
[ \t] ;
\n {if(flag==1){
        printf("Accepted \n");
    }
    else{
        printf("Rejected \n");
    }
    flag=1;
    }
. ;

%%

int main(){
    printf("Enter the string : ");
    yylex();
    return 0;
}

int yywrap(){
    return 1;
}