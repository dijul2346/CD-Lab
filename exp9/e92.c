#include<stdio.h>
#include<ctype.h>
#include<string.h>

char postfix[100];

int precedence(char a) {
    switch(a){
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

struct ThreeAC{
    char arg1[10];
    char arg2[10];
    char op;
    char result[10];
}tac[100];

int tacc=0,pf=0;

void convertPostfix(char *input){
    int i=0,top=-1;
    pf=0;
    char stack[100];
    while(input[i]!='\0'){

        if(isalnum(input[i])){
            postfix[pf++]=input[i++];
        }
        else if(input[i]=='('){
            stack[++top]=input[i++];
        }
        else if(input[i]==')'){
            while(top != -1 && stack[top]!='('){
                postfix[pf++]=stack[top--];
            }
            i++;
            top--;
        }
        else{
            while (top!=-1 && (precedence(stack[top])>precedence(input[i])))
            {
                postfix[pf++]=stack[top--];
            }
            stack[++top]=input[i++];
        }
    }
    while(top!=-1){
        postfix[pf++]=stack[top--];
    }
    postfix[pf]='\0';
}

void find3AC(){
    char stack[10][10];
    int top=-1;
    int t=0;
    for(int i=0;i<pf;i++){
        if(isalnum(postfix[i])){
            sprintf(stack[++top],"%c",postfix[i]);
        }
        else{
            strcpy(tac[tacc].arg2,stack[top--]);
            strcpy(tac[tacc].arg1,stack[top--]);
            tac[tacc].op=postfix[i];
            sprintf(tac[tacc].result,"t%d",t);
            sprintf(stack[++top],"t%d",t++);
            tacc++;
        }
    }

}

void print3AC(){
    printf("Three Address Code:\n");
    for(int i=0; i<tacc; i++){
        printf("%s = %s %c %s\n", tac[i].result, tac[i].arg1, tac[i].op, tac[i].arg2);
    }
}


void main(){
    char input[100];
    printf("Enter the expression: ");
    scanf("%s", input);
    
    convertPostfix(input);
    printf("Postfix expression: %s\n", postfix);
    find3AC();
    print3AC();
}