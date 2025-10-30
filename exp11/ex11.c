#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

char postfix[100];
int pf=0;

struct var{
	char name[10];
	int value;
}v[10];
int vc=4;

struct three{
	char arg1[10];
	char arg2[10];
	char result[10];
	char op;
}tac[10];
int tp=0;

void find3ac(){
	char stack[10][10];
	int top=-1;
	int t=0;
	for(int i=0;i<pf;i++){
		if(isalnum(postfix[i])){
			sprintf(stack[++top],"%c",postfix[i]);
		}
		else{
			strcpy(tac[tp].arg2,stack[top--]);
			strcpy(tac[tp].arg1,stack[top--]);
			tac[tp].op=postfix[i];
			sprintf(tac[tp].result,"t%d",t);
			sprintf(stack[++top],"t%d",t++);
			tp++;
		}
	}
}

void print3AC(){
	for(int i=0;i<tp;i++){
		printf("%s=%s %c %s\n",tac[i].result,tac[i].arg1,tac[i].op,tac[i].arg2);
	}
}

int precedence(char op){
	if(op=='+' || op=='-'){
		return 0;
	}
	if(op=='*' || op=='/'){
		return 1;
	}
	if(op=='^'){
		return 2;
	}
}
void convertPostfix(char *ip){
	int i=0;
	char stack[100];
	int top=-1;
	while(ip[i] != '\0'){
		if(isalnum(ip[i])){
			postfix[pf++]=ip[i++];
		}
		else if(ip[i] =='('){
			stack[++top] == ip[i];
		}
		else if(ip[i] == ')'){
			while(top != -1 && stack[top]!='('){
				postfix[pf++]==stack[top--];
			}
			if(top !=-1){
				top--;
			}
		}
		else{
			while(top != -1 && precedence(stack[top]) >= precedence(ip[i])){
				postfix[pf++]= stack[top--];
			}
			stack[++top]=ip[i++];
		}
	}
	while(top != -1){
			postfix[pf++]=stack[top--];
	}
}

int findvalue(char *value){
	for(int i=0;i<vc;i++){
		if(strcmp(v[i].name,value)==0){
			return v[i].value;
		}
	}
}

void calculate(){
	int temp=0;
	for(int i=0;i<tp;i++){
		int arg1=(findvalue(tac[i].arg1));
		int arg2=(findvalue(tac[i].arg2));

		
		switch(tac[i].op){
			case '+': temp=arg1+arg2;break;
			case '-': temp=arg1-arg2;break;
			case '*': temp=arg1*arg2;break;
			case '/': temp=arg2*arg2;break;
		}
		v[vc].value=temp;
		strcpy(v[vc].name,tac[i].result);
		vc++;
		
	}
}

void cp(){
	for(int i=0;i<tp;i++){
		if(strcmp(tac[i].arg1,"x")==0){
			sprintf(tac[i].arg1,"%d",findvalue("x"));
		}
		else if(strcmp(tac[i].arg1,"y")==0){
			sprintf(tac[i].arg1,"%d",findvalue("y"));
		}
		if(strcmp(tac[i].arg2,"x")==0){
			sprintf(tac[i].arg2,"%d",findvalue("x"));
		}
		else if(strcmp(tac[i].arg2,"y")==0){
			sprintf(tac[i].arg2,"%d",findvalue("y"));
		}
	}
}



void main(){
	char ip[100];
	printf("Enter the input expression:");
	scanf(" %s",ip);
	for(int i=0;i<4;i++){
		switch(i){
			case 0:{
				printf("Enter the value for a");
				scanf("%d",&v[i].value);
				strcpy(v[i].name,"a");
				break;
			}
			case 1:{
				printf("Enter the value for b");
				scanf("%d",&v[i].value);
				strcpy(v[i].name,"b");
				break;
			}
			case 2:{
				printf("Enter the value for constant x: ");
				scanf("%d",&v[i].value);
				strcpy(v[i].name,"x");
				break;
			}
			case 3:{
				printf("Enter the value for constant y: ");
				scanf("%d",&v[i].value);
				strcpy(v[i].name,"y");
				break;
			}
		}
	}
	convertPostfix(ip);
	printf("\n%s\n",postfix);
	find3ac();
	printf("\n3 Address code before constant propogation\n");
	print3AC();
	calculate();
	cp();
	printf("\n3 Address code after constant propogation\n");
	print3AC();
	printf("Final result %d\n",v[vc-1].value);
}
