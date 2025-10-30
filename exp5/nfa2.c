#include<stdio.h>

struct TRANSITION{
    int from,to;
    char symbol;
}transitions[50];

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
            if(transitions[i].from==curr && transitions[i].symbol=='e' && !visited[transitions[i].to]){
                stack[++top]=curr;
                visited[transitions[i].to]=1;
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
    scanf("%d",&symbolCount);

    printf("Enter the symbols : ");
    for(int i=0;i<symbolCount;i++){
        scanf("%c",symbols[i]);
    }

    printf("Enter the number of transitions : ");
    scanf("%d",&transitionCount);

    printf("Enter the transitions(from symbol to):\n");
    for(int i=0;i<transitionCount;i++){
        scanf("%d %c %d",&transitions[i].from,&transitions[i].symbol,&transitions[i].to);
    }

    printf("\nE-closure:\n");
    for(int i=0;i<stateCount;i++){
        int c=findClosure(i,closure);
        printf("E - Closure (q%d) = { ",i);
        for(int j=0;j<c;j++){
            printf("q%d ",closure[j]);
        }
        printf("}\n");
    }

}