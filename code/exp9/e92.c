#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int precedence(char a){
    switch(a){
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '/': return 2;
        case '^': return 3;
        default : return 0;
    }
}

struct threeAC
{
    char arg1[10];
    char arg2[10];
    char op;
    char result[10];
}tac[100];
int cd=0;

char postfix[100];
int p=0;

void convertPostfix(char *input){
    int i=0;
    char stack[100];
    int top=-1;
    while(input[i]!='\0'){
        if(isalnum(input[i])){
            postfix[p++]=input[i];
        }
        else if(input[i]=='('){
            stack[++top]=input[i];
        }
        else if(input[i]==')'){
            while(stack[top]!='('){
                postfix[p++]=stack[top--];
            }
            stack[top--];
        }
        else{
            while(top !=-1 && precedence(input[i])<=precedence(stack[top])){
                postfix[p++]=stack[top--];
            }
            stack[++top]=input[i];
        }
        i++;
    }
    while(top!=-1){
        postfix[p++]=stack[top--];
    }
    postfix[p]='\0';
}

void create3AC(char *postfix){
    char stack[100][100];
    int top=-1,t=0;

    for(int i=0;postfix[i]!='\0';i++){
        if(isalnum(postfix[i])){
            stack[++top][0]=postfix[i];
            stack[top][1]='\0';
        }
        else{
            char op1[100],op2[100],temp[100];
            strcpy(tac[cd].arg2,stack[top--]);
            strcpy(tac[cd].arg1,stack[top--]);
            sprintf(temp,"t%d",t++);
            strcpy(tac[cd].result,temp);
            tac[cd].op=postfix[i];
            cd++;
            strcpy(stack[++top],temp);
        }
    }
}

void print3AC(){
    printf("Three Address Code:\n");
    for(int i=0;i<cd;i++){
        printf("%s = %s %c %s\n",tac[i].result,tac[i].arg1,tac[i].op,tac[i].arg2);
    }
}



void main(){
    char input[100];
    printf("Enter the expression: ");
    scanf("%s", input);
    
    convertPostfix(input);
    printf("Postfix expression: %s\n", postfix);
    create3AC(postfix);
    print3AC();
}