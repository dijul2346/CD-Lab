#include<stdio.h>

struct TRANSITION{
    int from;
    int to;
    char input;
}transitions[50];

int transition,states;

void main(){
    printf("Enter the no  of states");
    scanf("%d",&states);
    printf("Enter the no of transitions:");
    scanf("%d",&transition);

    printf("ENTER the transitions : \n");
    for(int i=0;i<=transition;i++){
        printf("Enter from state : ");
        scanf("%d",&transitions[i].from);
        printf("Enter the to state");
        scanf("%d",&transitions[i].to);
        printf("Enter the input symbol (e for epsilon) :");
        scanf("%c",&transitions[i].input);
    }

    printf("Transitions are as follows : \n");
    for(int i=0;i<transition;i++){
        printf("q%d -> q%d {input = %c}\n",transitions[i].from,transitions[i].to,transitions[i].input);
    }

    for(int i=0;i<states;i++){
        int curr_state = i;
        int closure[50];
        int top = 0;
        closure[top]=curr_state;
        top+=1;

        for(int j=0;j<transition;j++){
            if((transitions[j].from == curr_state || transitions[j].from == i) && (transitions[j].input=='e')){
                curr_state=transitions[j].to;
                closure[top]=curr_state;
                top++;
            }        
        }
        printf("Closure of state q%d = {",i); 
        for(int j=0;j<top;j++){ 
            printf(" q%d ",closure[j]); 
        } 
        printf("}\n"); 
    }
}