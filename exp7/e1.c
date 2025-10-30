#include<stdio.h>
#include<string.h>
#include<ctype.h>

char productions[20][20];
char nt[20];
int n,ntCount=0;

int isNonTerminal(char c) {
    return isupper(c);
}

void addToSet(char set[],char c){
    if(!strchr(set,c)){
        int len=strlen(set);
        set[len]=c;
        set[len+1]='\0';
    }
}

void firstFind(char result[],char symbol){
    if(!isNonTerminal(symbol) && symbol !='#'){
        addToSet(result,symbol);
        return;
    }

    for(int i=0;i<n;i++){
        if(productions[i][0] != symbol)
            continue;
            
    }
}

int main(){
    char result[20];
    printf('Enter number of productions : ');
    scanf("%d", &n);

    printf("Enter productions : \n");
    for (int i = 0; i < n; i++) {
        scanf("%s",productions[i]);

        int flag=0;
        for(int j=0;j<ntCount;j++){
            if(nt[i]==productions[i][0])
                flag=1;
        }
        if(!flag)
            nt[ntCount++]=productions[i][0];
    }
    
    printf("\nProductions:\n");
    for (int i = 0; i < n; i++)
        printf("%s\n", productions[i]);
    printf("\n");

    for(int i=0;i<ntCount;i++){
        strcpy(result,"");
        
    }

}