%{
    #include<stdio.h>
    #include<string.h>
    int na=0,nb=0,flag=1,sb=0;
%}

%%
"a" {
    if(sb)
        flag=0;
    na++;
}

"b" {
    sb=1;
    nb++;
}

[c-zA-Z0-9]+ {flag=0;}

[ \t] ;
\n {
    if(na==0 && nb==0)
        flag=0;
    if(na%2!=0 && na!=0)
        flag=0;
    if(nb%2==0 && nb!=0)
        flag=0;
    if(flag){
        printf("Accepted\n");
    }
    else{
        printf("Rejected\n");
    }
    sb=0,na=0,nb=0;
    flag=1;
}

%%


int main(){
    printf("Enter a string : ");
    yylex();
    return 0;
}

int yywrap(){
    return 1;
}