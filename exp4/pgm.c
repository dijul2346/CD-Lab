#include<stdio.h>
#include<stdlib.h>

struct TRANSITION{
  int from;
  int to;
  char input;
}transitions[20];
int trans,states;

void main(){
  printf("Enter the number of states : ");
  scanf("%d",&states);
  printf("Enter the number of transition : ");
  scanf("%d",&trans);

  for(int i=0;i<trans;i++){
    printf("\nEnter the from state : ");
    scanf("%d",&transitions[i].from);
    printf("\nEnter the to state : ");
    scanf("%d",&transitions[i].to);
    printf("\nEnter the input sybol (e for epsilon): ");
    scanf("%c",&transitions[i].input);
  }
  printf("\n Transitions \n");
  for(int i=0;i<trans;i++){
    printf("q%d\t q%d \t %c",transitions[i].from,transitions[i].to,transitions[i].input);
  }

  for(int i=0;i<states;i++){
    int curr_state=i;
    int closure[50],top=-1;
    closure[++top]=curr_state;

    for(int j=0;j<trans;j++){
      if((transitions[j].from==curr_state || transitions[j].from==i) && transitions[j].input=='e'){
        curr_state=transitions[j].to;
        closure[++top]=curr_state;
      }
    }
    printf("Closure of state q%d = {",i); 
    for(int k=0;k<top;k++){
      printf( "q%d ",closure[k]);
    }
    printf("}");
  }


}