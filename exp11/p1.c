#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>

struct CODE{
    char op;
    char var1[10];
    char var2[10];
    char res[10];
}code[20];

struct VALUE{
    char var[10];
    int val;
}val[10];

int main(){
    int n,c=0;
    printf("Enter the no of statements : ");
    scanf("%d",&n);
    // for(int i=0;i<n;i++){
    //     printf("Statement %d",i);
    //     scanf("%s = %s %c %s",code[i].res,code[i].var1,&code[i].op,code[i].var2);
    // }

    for(int i=0;i<n;i++){
        
        printf("Statement %d",i);
        scanf("%s = %s %c %s",code[i].res,code[i].var1,&code[i].op,code[i].var2);
        for(int j=0;j<c;j++){
            if(strcmp(code[i].var1,val[j].var)==0){
                sprintf(code[i].var1,"%d",val[j].val);
                
            }
            if(strcmp(code[i].var2,val[j].var)==0){
                sprintf(code[i].var2,"%d",val[j].val);
                
            }
        }
        printf("%d %s %s\n",c,code[i].var1,code[i].var2);
        if(isdigit(code[i].var1[0]) && (code[i].op=='_' || isdigit(code[i].var2[0]))){
            int v1=atoi(code[i].var1);
            int v2=(code[i].op != '_') ? atoi(code[i].var2) : 0;
            int result=0;
            printf("%d  %d  %c\n",v1,v2,code[i].op);

            switch(code[i].op){
                case '+':
                    result=v1+v2;
                    break;
                case '-':
                    result=v1-v2;
                    break;
                case '*':
                    result=v1*v2;
                    break;
                case '/':
                    result=(v2 !=0) ? v1/v2 : 0;
                    break;
                case '_':
                    result=v1;
                    break;
                default:
                    continue;
            }

            strcpy(val[c].var,code[i].res);
            val[c++].val=result;
            sprintf(code[i].var1,"%d",result);
            code[i].op='_';
            strcpy(code[i].var2,"_");
        }
    }
    printf("After Constant Propogation : ");
    for(int i=0;i<n;i++){
        printf("%s = %s ",code[i].res,code[i].var1);
        if(code[i].op != '_'){
            printf("%c %s",code[i].op,code[i].var2);
        }
        printf("\n");
    }
        
    return 0;

}