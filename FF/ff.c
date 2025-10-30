#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char productions[20][20];
char nt[20];
int n,ntc=0;

int isNonTerminal(char c){
    return isupper(c);
}

void addToSet(char set[],char c){
    int len=strlen(set);
    if(!strchr(set,c)){
        set[len]=c;
        set[len+1]='\0';
    }
    
}

void findFirst(char result[],char symbol){
    if(!isNonTerminal(symbol)){
        addToSet(result,symbol);
        return;
    }

    for(int i=0;i<n;i++){
        if(productions[i][0] != symbol)
            continue;
        
            if(productions[i][2] == '#'){
                addToSet(result,'#');
                continue;
            }

            int k=2,epsilon =1;
            while(productions[i][k] && epsilon){
                char next = productions[i][k++];
                char temp[20] = "";
                findFirst(temp,next);

                for(int j=0;temp[j];j++)
                    if(temp[j] != '#')
                        addToSet(result,temp[j]);
                
                    epsilon=strchr(temp,'#') !=NULL;
            }
            if(epsilon)
                addToSet(result,'#');
    }
}

void findFollow(char result[],char symbol){
    if(productions[0][0] == symbol){
        addToSet(result,'$');
    }
    for(int i=0;i<n;i++){
        for(int j=2;productions[i][j];j++){
            if(productions[i][j]!= symbol)
                continue;
            int k=j+1,epsilon=1;
            while(productions[i][k] && epsilon){
                char next = productions[i][k++];
                if(!isNonTerminal(next) && next !='#'){
                    epsilon=0;
                    addToSet(result,next);
                    break;
                }
                char temp[20] = "";
                findFirst(temp,next);

                for(int m=0;temp[m];m++)
                    if(temp[m] != '#')
                        addToSet(result,temp[m]);
                
                    epsilon=strchr(temp,'#') !=NULL;
            }

            if(epsilon && productions[i][0] !=symbol){
                char next = productions[i][k++];
                char temp[20] = "";
                findFollow(temp,next);

                for(int m=0;temp[m];m++)
                    addToSet(result,temp[m]);
            }

        }
        
    }
}

void main(){
    char result[20];
    printf("Enter the number of productions : ");
    scanf("%d",&n);

    printf("Enter the productions : \n");
    for(int i=0;i<n;i++){
        scanf("%s",productions[i]);

        int flag=1;
        for(int j=0;j<ntc;j++){
            if(nt[j] == productions[i][0]){
                flag=0;
                break;
            }
        }
        if(flag)
            nt[ntc++]=productions[i][0];
    }

    printf("\nProductions:\n");
    for (int i = 0; i < n; i++)
        printf("%s\n", productions[i]);
    printf("\n");

    for(int i=0;i<ntc;i++){
        strcpy(result,"");
        findFirst(result,nt[i]);
        printf("FIRST(%c) = { ",nt[i]);
        for(int j=0;result[j];j++)
            printf("%c%s",result[j],result[j+1]? ", " : "");
        printf(" }\n");
    }

    printf("\n");

    for(int i=0;i<ntc;i++){
        strcpy(result,"");
        findFollow(result,nt[i]);
        printf("FOLLOW(%c) = { ",nt[i]);
        for(int j=0;result[j];j++)
            printf("%c%s",result[j],result[j+1]? ", " : "");
        printf(" }\n");
    }

}