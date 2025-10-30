#include<stdio.h>
char table[6][6]={
	'=','>','>','>','>','>',
	'<','>','<','>','>','>',
	'<','>','>','>','>','>',
	'<','<','<','=','<','<',
	'<','<','<','>','<','<',
	'>','>','>','>','>','>',
};
char op[6]={'i','+','*','$','(',')'};
char stack[50],s[50];
int top=-1,i;
void push(char c){
	stack[++top]=c;
}

char pop(){
	return stack[top--];
}

int findPos(char ch){
	int k=0;
	for(k=0;k<6;k++){
		if(ch==op[k]){
			return k;
		}
	}
	return k;
}

void displayStack(){
	int j=0;
	while(j<=top){
		printf("%c",stack[j]);
		j++;
	}
	printf("\t\t\t");
}

void displayString(){
	int j=i;
	while(s[j]!='\0'){
		printf("%c",s[j]);
		j++;
	}
	printf("\t\t\t");
}

void parse(){
	char ch,ch1,opr;
	int pos1,pos2;
	printf("Enter the expression (end with $): ");
	scanf("%s", s);
	push('$');
	i=0;
	while(1){
		displayStack();
		displayString();
		if(stack[top]=='$' && s[i]=='$'){
			printf("Valid Expression\n");
			return;
		}
		else{
			ch=s[i];
			pos2=findPos(ch);
			pos1=findPos(stack[top]);
			if(stack[top]=='e'){
				pos1=findPos(stack[top-1]);
				if(ch=='$' && stack[top-1]=='$'){
					printf("Valid Expression\n");
					return;
				}
			}
			if(pos1==6 || pos2==6){
				printf("Invalid Expression\n");
				return;
			}
			opr = table[pos1][pos2];
			if(opr=='<' || opr=='='){
				push(ch);
				i++;
				printf("Shift\n");
			}
			else if(opr == '>'){
				ch1=pop();
				if(ch1 == 'i'){
					push('e');
				}
				else if(ch1=='e'){
					if(stack[top]=='$'){
						continue;
					}
					else if((stack[top]=='*'||stack[top]=='+')&& (stack[top-1]=='e')){
						pop();
					}
					else{
						printf("Invalid Expression\n");
						return;
					}
				}
				else if(ch==')'){
					if (stack[top]=='e' && stack[top-1]=='('){
						pop();
						pop();
						push('e');
					}
				}
				else{
					printf("Invalid Expression\n");
					return;
				}
				printf("Reduce\n");
			}
			else{
				printf("Invalid Expression\n");
				return;
			}
		}
	}
}
					
void main(){
	parse();
}