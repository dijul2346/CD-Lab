#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char postfix[100];
int pf=0;

struct var{
    char name[10];
    int value;
}v[10];
int vc=0;

struct TAC{
    char arg1[10],arg2[10],result[10];
    char op;
}tac[10];
int tp=0;

int precedence(char op){
    if(op=='+'||op=='-') return 1;
    if(op=='*'||op=='/') return 2;
    if(op=='^') return 3;
}

int findValue(char *name) {
    for (int i = 0; i < vc; i++)
        if (strcmp(v[i].name, name) == 0)
            return v[i].value;
    return atoi(name); 
}

void convertPostfix(char *input){
    char stack[100];
    int top=-1,i=0;
    while(input[i]!='\0'){
        if(isalnum(input[i])){
            postfix[pf++]=input[i++];
        }
        else if(input[i]=='('){
            stack[++top]=input[i++];
        }
        else if(input[i]==')'){
            while(top>-1 && stack[top]!='('){
                postfix[pf++]=stack[top--];
            }
        }
        else{
            while(top>-1 && precedence(stack[top])>=precedence(input[i])){
                postfix[pf++]=stack[top--];
            }
            stack[++top]=input[i++];
        }
    }
    while(top>-1){
        postfix[pf++]=stack[top--];
    }
    postfix[pf]='\0';
}

void generate3AC(){
    char stack[10][10];
    int top=-1,t=0;

    for(int i=0;postfix[i]!='\0';i++){
        if(isalnum(postfix[i])){
            sprintf(stack[++top],"%c",postfix[i]);
        }
        else{
            strcpy(tac[tp].arg2,stack[top--]);
            strcpy(tac[tp].arg1,stack[top--]);
            tac[tp].op=postfix[i];
            sprintf(tac[tp].result,"t%d",t);
            sprintf(stack[++top],"t%d",t++);
            tp++;
        }
    }
}

void print3AC(){
    for(int i=0;i<tp;i++){
        printf("%s = %s %c %s\n",tac[i].result,tac[i].arg1,tac[i].op,tac[i].arg2);
    }
}

void constantPropogation(){
    for(int i=0;i<tp;i++){
        for(int j=0;j<vc;j++){
            if(strcmp(tac[i].arg1,v[j].name)==0)
                sprintf(tac[i].arg1,"%d",v[j].value);
            if(strcmp(tac[i].arg2,v[j].name)==0)
                sprintf(tac[i].arg2,"%d",v[j].value);
        }
    }
}

void evaluate(){
    for(int i=0;i<tp;i++){
        int a=findValue(tac[i].arg1);
        int b = findValue(tac[i].arg2);
        int res=0;

        switch(tac[i].op){
            case '+':res=a+b;break;
            case '-': res = a - b; break;
            case '*': res = a * b; break;
            case '/': res = b ? a / b : 0; break;
        }
        strcpy(v[vc].name,tac[i].result);
        v[vc++].value=res;
    }
}

void main(){
    char input[100];
    printf("Enter the infix expression: ");
    scanf("%s", input);
    char names[][2]={"a","b","x","y"};
    for(int i=0;i<4;i++){
        printf("Enter the value for %s: ", names[i]);
        strcpy(v[vc].name,names[i]);
        scanf("%d",&v[vc++].value);
    }

    convertPostfix(input);
    printf("\nPostfix Expression: %s\n", postfix);

    generate3AC();
    printf("\n--- 3 Address Code (Before Constant Propagation) ---\n");
    print3AC();

    constantPropogation();
    printf("\n--- 3 Address Code (After Constant Propagation) ---\n");
    print3AC();

    evaluate();
    printf("\nFinal Result = %d\n", v[vc - 1].value);


}