#include <stdio.h>
#include <ctype.h>
#include <string.h>

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

struct ThreeAC {
    char arg1[10];
    char arg2[10];
    char op;
    char result[10];
}tac[100];
int tacc = 0;

void convertToPostfix(char *input) {
    int i = 0, pf = 0, top = -1;
    char stack[100];
    
    while(input[i] != '\0') {
        if(isalnum(input[i])){
            postfix[pf++] = input[i++];
        } 
        else if(input[i] == '('){
            stack[++top] = input[i++];
        } 
        else if(input[i] == ')'){
            while(top != -1 && stack[top] != '(') {
                postfix[pf++] = stack[top--];
            }
            top--;
            i++;
        } 
        else{ 
            while(top != -1 && precedence(stack[top]) >= precedence(input[i])){
                postfix[pf++] = stack[top--];
            }
            stack[++top] = input[i++];
        }
    }
    
    while(top != -1) {
        postfix[pf++] = stack[top--];
    }
    
    postfix[pf] = '\0';
}

void find3AC(char *postfix){
    char stack[100][100];
    char temp[100];
    int top = -1, t = 1;
    for(int i=0;postfix[i] != '\0'; i++){
        if(isalnum(postfix[i])){
            stack[++top][0] = postfix[i];
            stack[top][1] = '\0';
        }
        else{
            char op2[100],op1[100];
            strcpy(op2,stack[top--]);
            strcpy(op1,stack[top--]);
            sprintf(temp, "t%d", t++);
            tac[tacc].op = postfix[i];
            strcpy(tac[tacc].arg1, op1);
            strcpy(tac[tacc].arg2, op2);
            strcpy(tac[tacc].result, temp);
            tacc++;
            strcpy(stack[++top], temp);
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
    
    convertToPostfix(input);
    printf("Postfix expression: %s\n", postfix);

    find3AC(postfix);
    print3AC();
}