#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define SIZE 20

char productions[SIZE][SIZE],nonterminals[SIZE];
int n,ntcnt=0;

void removeSpace(char* str){
	int i=0,cnt=0;
	while(str[i]!='\0'){
		if(str[i]!=' '){
			str[cnt]=str[i];
			cnt++;
		}
		i++;
	}
	str[cnt]='\0';
}

void addToResultSet(char result[],char c){
	int i=0;
	while(result[i]!='\0'){
		if(result[i]==c){
			return;
		}
		i++;
	}
	int len=strlen(result);
	result[len]=c;
	result[len+1]='\0';
}

void FIRST(char result[],char c){
	if(!isupper(c) && c!='#'){
		addToResultSet(result,c);
		return;
	}
	for(int i=0;i<n;i++){
		if(productions[i][0]==c){
			if(productions[i][3]=='#'){
				addToResultSet(result,'#');
			}
			else{
				int k=3,hasEpsilon=1;
				while(productions[i][k]!='\0' && hasEpsilon){
					char next=productions[i][k],temp[SIZE]="";
					FIRST(temp,next);
					for(int j=0;temp[j]!='\0';j++){
						if(temp[j]!='#'){
							addToResultSet(result,temp[j]);
						}
					}
					hasEpsilon= (strchr(temp,'#')!=NULL);
					k++;
				}
				if(hasEpsilon){
					addToResultSet(result,'#');
				}
			}
		}
	}
}

void FOLLOW(char result[],char c){
	if(productions[0][0]==c){
		addToResultSet(result,'$');
	}
	for(int i=0;i<n;i++){
		for(int j=3;productions[i][j]!='\0';j++){
			if(productions[i][j]==c){
				int k=j+1,allEpsilon=1;
				while(productions[i][k]!='\0' && allEpsilon){
					char next=productions[i][k];
					if(!isupper(next) && next!='#'){
						addToResultSet(result,next);
						allEpsilon=0;
						break;
					}
					char temp[SIZE]="";
					FIRST(temp,next);
					for(int m=0;temp[m]!='\0';m++){
						if(temp[m]!='#'){
							addToResultSet(result,temp[m]);
						}
					}
					allEpsilon=(strchr(temp,'#')!=NULL);
					k++;
				}
				if(allEpsilon && productions[i][0]!=c){
					char ftemp[SIZE]="";
					FOLLOW(ftemp,productions[i][0]);
					for(int m=0;ftemp[m]!='\0';m++){
						addToResultSet(result,ftemp[m]);
					}
				}
			}
		}
	}
}
int main(){
	printf("Enter the number of productions : ");
	scanf("%d",&n);
	getchar();
	
	printf("Enter the productions : \n");
	for(int i=0;i<n;i++){
		printf("P%d : ",i+1);
		char input[SIZE];
		fgets(input,SIZE,stdin);
		input[strcspn(input,"\n")]='\0';
		removeSpace(input);
		strcpy(productions[i],input);
		
		int already=0;
		for(int j=0;j<ntcnt;j++){
			if(nonterminals[j]==productions[i][0]){
				already=1;
				break;
			}
		}
		
		if(!already){
			nonterminals[ntcnt++]=productions[i][0];
		}
	}
	printf("\nProductions : \n");
	for(int i=0;i<n;i++){
		printf("%s\n",productions[i]);
	}
	
	char result[SIZE];
	printf("\nFIRST SET\n");
	for(int i=0;i<ntcnt;i++){
		char c=nonterminals[i];
		strcpy(result,"");
		FIRST(result,c);
		printf("FIRST(%c) = {",c);
		for(int j=0;result[j]!='\0';j++){
			printf(" %c ",result[j]);
			if(result[j+1]!='\0'){
				printf(", ");
			}
		}
		printf("}\n");
	}
	printf("\nFOLLOW SET\n");
	for(int i=0;i<ntcnt;i++){
		char c=nonterminals[i];
		strcpy(result,"");
		FOLLOW(result,c);
		printf("FOLLOW(%c) = {",c);
		for(int j=0;result[j]!='\0';j++){
			if(result[j]=='$'){
				printf(" $ ");
			}
			else{
				printf(" %c ",result[j]);
			}
			if(result[j+1]!='\0'){
				printf(", ");
			}
		}
		printf("}\n");
	}
}