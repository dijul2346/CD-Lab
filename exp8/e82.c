#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

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
int top=-1,i=0;

void push(char c){
	stack[++top]=c;
}

char pop(){
	return stack[top--];
}

int findPos(char c){
    int k;
    for(k=0;k<6;k++){
        if(op[k]==c){
            return k;
        }
    }
    return 6;
}


void displayStack(){
    int j=0;
	while(j<=top){
		printf("%c",stack[j]);
		j++;
	}
    printf("\t\t\t");
}

void displayStr(){
    int k=i;
    while(s[k]!='\0'){
        printf("%c ",s[k]);
        k++;
    }

    printf("\t\t\t");
}

void parse(){
    char ch,ch1,opr;
	int pos1,pos2;
    printf("Enter a string ending with $");
    scanf("%s",s);
    push('$');
    i=0;
    printf("\n");
    while(1){
        displayStack();
        displayStr();

        if(stack[top]=='$' && s[i]=='$'){
            printf("Accepted");
            return;
        }
        else{
            ch=s[i];
            pos1=findPos(stack[top]);
            pos2=findPos(ch);

            if(stack[top]=='e'){
                pos1=findPos(stack[top-1]);
                if(stack[top-1]=='$' && ch=='$'){
                    printf("Accepted");
                    return;
                }
            }

            if(pos1==6 || pos2 ==6){
                printf("Invalid 1");
                return;
            }

            opr=table[pos1][pos2];

            if(opr == '<' || opr == '='){
                push(ch);
                i++;
                printf("Shift \n");
            }
            else if(opr=='>')
            {
                ch1=pop();
                if(ch1=='i'){
                    push('e');
                }
                else if(ch1 == 'e'){
                    if(stack[top]=='$'){
                        continue;
                    }
                    else if((stack[top]=='+'||stack[top]=='*') && (stack[top-1]=='e')){
                        pop();
                    }
                    else{
                        printf("Invalid 2");
                        return;
                    }
                }else if(ch==')'){
					if (stack[top]=='e' && stack[top-1]=='('){
						pop();
						pop();
						push('e');
					}
				}
                else{
					printf("Invalid Expression3\n");
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