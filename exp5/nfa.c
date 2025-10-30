#include<stdio.h>

struct TRANSITION{
	int from;
	int to;
	char symbol;
}transitions[50];

int transitionCount,states;
int visited[50];


int findClosure(int state,int closure[]){
	int closureCount = 0,top = 0;
	int stack[50];
	stack[top++] = state;
	for(int i=0;i<states;i++){
		visited[i] = 0;
	}
	visited[state] = 1;
	
	while(top > 0){
		int curr = stack[--top];
		closure[closureCount++] = curr;
		for(int k=0;k<transitionCount;k++){
			if(transitions[k].from == curr && visited[transitions[k].to]==0 && transitions[k].symbol == 'e'){
				stack[top++] = transitions[k].to;
				visited[transitions[k].to] = 1;
			}
			
		}
	}
	return closureCount;
}


int convertEnfa(int symbolCount, char symbols[]){
	for(int q=0;q<states;q++){
		int closure[50];
		int closureCount = findClosure(q,closure);
		for(int k=0;k<symbolCount;k++){
			char input = symbols[k];
			int reachable[50];
			int rCount = 0;
			int marked[50] = {0};
			for(int i=0;i<closureCount;i++){
				int st = closure[i];
				for(int t=0;t<transitionCount;t++){
					if(transitions[t].from == st && transitions[t].symbol == input){
						int subClosure[50];
						int subCount = findClosure(transitions[t].to,subClosure);
						for(int c=0;c<subCount;c++){
							if(!marked[subClosure[c]]){
								reachable[rCount++] = subClosure[c];
								marked[subClosure[c]] = 1;
							}
						}
					}
				}
			}
			printf("transition(q%d,%c) = {",q,input);
			for(int i=0;i<rCount;i++){
				printf("q%d ",reachable[i]);
			}
			printf("}\n");
		}
	}
}


int main(){

	int symbolCount;
	char symbols[10];
	int closure[50];
	printf("Enter no of states: ");
	scanf("%d",&states);
	printf("Enter the no of symbols: ");
	scanf("%d",&symbolCount);
	printf("Enter the input symbols : ");
	for(int i=0;i<symbolCount;i++){
		scanf(" %c",&symbols[i]);	
	}
	printf("Enter the no of transitions: ");
	scanf("%d",&transitionCount);
	printf("Enter from - symbol - next");
	for(int i=0;i<transitionCount;i++){
		scanf("%d %c %d",&transitions[i].from,&transitions[i].symbol,&transitions[i].to);
	}
	
	printf("\ne closures : \n");
	for(int i=0;i<states;i++){
		int closureCount = findClosure(i,closure);
		printf("Closure of q%d = { ",i);
		for(int j=0;j<closureCount;j++){
			printf("q%d ",closure[j]);
			}
		printf("}\n");
	}
	
	printf("\nNFA transitions after removing e transitions are : \n");
	convertEnfa(symbolCount,symbols);
	return 0;
}