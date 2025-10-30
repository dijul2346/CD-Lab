#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

struct TAC{
    char res[10],op,op1[10],op2[10];
}code[20];

void main(){
    int n;
    printf("Enter the number of lines : ");
    scanf("%d",&n);

    printf("Enter the three address code : ");
    for(int i=0;i<n;i++){
        printf("L : ");
        scanf(" %s = %s %c %s",code[i].res,code[i].op1,&code[i].op,code[i].op2);
    }

    printf("Assembly Code : ");
    for(int i=0;i<n;i++){
        char reg[10];
        sprintf(reg,"R%d",i);

        if(code[i].op == '_'){
            printf("MOV %s %s\n",reg,code[i].op1);
        }
        else{
            printf("MOV %s %s\n",reg,code[i].op1);

            switch(code[i].op){
                case '+':
                    printf("ADD %s %s",reg,code[i].op2);
                    break;
                case '-':
                    printf("SUB %s %s",reg,code[i].op2);
                    break;
                case '*':
                    printf("MUL %s %s",reg,code[i].op2);
                    break;
                case '/':
                    printf("DIV %s %s",reg,code[i].op2);
                    break;
                default:
                    printf("INVALID");
                    break;
            }
            printf("MOV %s %s\n",code[i].res,reg);
        }
    }
}