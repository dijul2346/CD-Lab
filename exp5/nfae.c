#include<stdio.h>

struct TRANSITION{
    int from,to;
    char symbol;
}transition[50];

int stateCount,transitionCount;
int visited[50];

int findClosure(int state,int closure[]){
    int stack[50],top=-1,c=0;
    for(int i=0;i<stateCount;i++){
        visited[i]=0;
    }
    stack[++top]=state;
    visited[state]=1;

    while(top>-1){
        int curr=stack[top--];
        closure[c++]=curr;
        for(int i=0;i<transitionCount;i++){
            if(transition[i].from == curr && transition[i].symbol=='e' && visited[transition[i].to]==0){
                stack[++top]=curr;
                visited[transition[i].to]=1;
            }
        }
    }
}

int main(){
    int symbolCount,closure[50];
    char symbols[10];

    printf("Enter the number of states : ");
    scanf("%d",&stateCount);

    printf("Enter the number of symbols : ");
    scanf('%d',symbolCount);

    printf("Enter the symbols : ");
    for(int i=0;i<symbolCount;i++){
        scanf("%c",symbols[i]);
    }

    printf("Enter the number of transitions : ");
    scanf("%d",&transitionCount);

    printf("ENTER the transitions : \n");
    for(int i=0;i<=transition;i++){
        printf("Enter from state : ");
        scanf("%d",&transition[i].from);
        printf("Enter the to state");
        scanf("%d",&transition[i].to);
        printf("Enter the input symbol (e for epsilon) :");
        scanf("%c",&transition[i].symbol);
    }

    printf("\n E-closure : \n");
    for(int i=0;i<stateCount;i++){
        int c=findClosure(i,closure);
        printf("E - Closure (q%d) = { ",i);
        for(int j=0;j<c;j++){
            printf("q%d ",closure[j]);
        }
        printf("}\n");
    }
}