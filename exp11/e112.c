#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

struct Code{
    char res[10];
    char op1[10];
    char op2[10];
    char op;
}code[20];

struct VALUE{
    char var[10];
    int v;
}val[10];

int main(){
    int n,c=0;
    printf("Enter the number of statements : ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Statements %d : ",i);
        scanf("%s = %s %c %s",code[i].res,code[i].op1,&code[i].op,code[i].op2);

        for(int j=0;j<c;j++){
            if(strcmp(code[i].op1,val[j].var)==0){
                sprintf(code[i].op1,"%d",val[j].v);
            }
            if(strcmp(code[i].op2,val[j].var)==0){
                sprintf(code[i].op2,"%d",val[j].v);
            }
        }
        printf("%d %s %s\n",c,code[i].op1,code[i].op2);
        int v1=atoi(code[i].op1);
        int v2=(code[i].op != '_') ? atoi(code[i].op2) : 0;
        int result=0;

        switch(code[i].op){
            case '+':
                result=v1+v2;
                break;
            case '*':
                result=v1*v2;
                break;
            case '-':
                result=v1-v2;
                break;
            case '/':
                result= (v2 !=0) ? v1+v2 : 0;
                break;
            case '_':
                result=v1;
                break;
            default:
                    continue;
        }
        strcpy(val[c].var,code[i].res);
        val[c++].v=result;
        sprintf(code[i].op1,"%d",result);
        code[i].op='_';
        strcpy(code[i].op2,"_");
    }
    printf("After Cosntant Propogation : ");
    for(int i=0;i<n;i++){
        printf("%s = %s ",code[i].res,code[i].op1);
        if(code[i].op != '_'){
            printf("%c %s",code[i].op,code[i].op2);
        }
        printf("\n");
    }
    return 0;
}
        

        
