int main() 
{ 
yyin=fopen("data.txt","r"); 
yylex(); 
printf("No. of vowels: %d\n",vowels); 
printf("No. of consonants: %d\n",cons); 
return 0; 
} 
int yywrap(void) 
{ 
return 1; 
} 