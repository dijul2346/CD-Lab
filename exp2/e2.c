Experiment 2 
2.1 
Write a lex program to count the number of vowels and consonants from the given 
input file. 
Program 
%{ 
#include<stdio.h> 
int vowels=0,cons=0; 
%} 
%% 
[a|e|i|o|u|A|E|I|O|U] {vowels++;} 
[a-zA-Z] {cons++;} 
. ; 
%% 
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
data.txt 
hi 
hello world 
Output 
No. of vowels: 4 
No. of consonants: 8 
2.2 
Write a lex program to display the number of lines,words and characters in an input text. 
Program 
%{ 
#include<stdio.h> 
int lines=0,words=0,chars=0; 
%} 
%% 
[\n] {lines++;} 
[a-zA-Z0-9]+ {words++; chars+=yyleng;} 
. ; 
%% 
int main() 
{ 
yyin=fopen("data.txt","r"); 
yylex(); 
printf("No. of lines: %d\n",lines); 
printf("No. of words: %d\n",words); 
printf("No. of characters: %d\n",chars); 
return 0; 
} 
int yywrap(void) 
{ 
return 1; 
} 
data.txt 
hi 
hello world 
Output 
No. of lines: 2 
No. of words: 3 
No. of characters: 12 
2.3 
Write a lex program to implement lexical identifier to identify     
keyword,identifier,punctuators,special characters and operator 
Program 
%{ 
#include<stdio.h> 
%} 
%% 
"void"|"main"|"int"|"float"|"if"|"else"|"for" {printf("%s - Keyword\n",yytext);} 
[0-9]* {printf("%s - Digit\n",yytext);} 
[a-zA-Z][_a-zA-Z0-9]* {printf("%s - Identifier\n",yytext);} 
[a-zA-Z<>.]+ {printf("%s - Preprocessor directive\n",yytext);} 
[<|>|=|!|+|-|*|/]+ {printf("%s - Operator\n",yytext);} 
[(|)|{|}|,|;] {printf("%s - Punctuators\n",yytext);} 
%% 
int main() 
{ 
yyin=fopen("input.c","r"); 
yylex(); 
return 0; 
} 
int yywrap(void) 
{ 
return 1; 
} 
input.c 
#include<stdio.h> 
void main() 
{ 
int a,b,sum; 
a=10; 
b=20; 
sum=a+b; 
} 
Output 
#include<stdio.h> - Preprocessor directive 
void - Keyword 
main - Keyword 
( - Punctuators 
) - Punctuators 
{ - Punctuators 
int - Keyword 
a - Identifier 
, - Punctuators 
b - Identifier 
, - Punctuators 
sum - Identifier 
; - Punctuators 
a - Identifier 
= - Operator 
10 - Digit 
; - Punctuators 
b - Identifier 
= - Operator 
20 - Digit 
; - Punctuators 
sum - Identifier 
= - Operator 
a - Identifier 
+ - Operator 
b - Identifier 
; - Punctuators 
} - Punctuators 
2.4 
Write a lex program to chech whether the email entered is valid or not. 
Program 
%{ 
#include<stdio.h> 
%} 
%% 
[A-Za-z][A-Za-z0-9._%+-]*@[A-Za-z0-9.-]+\.[A-Za-z]{2,3}$ {printf("%s is valid\n",yytext);} 
\n 
[^\n]+ {printf("Invalid email\n");} 
%% 
int main() 
{ 
printf("Enter email: "); 
yylex(); 
return 0; 
} 
int yywrap(void) 
{ 
return 1; 
} 
Output 
Enter email: abc123@email.com 
abc123@email.com is valid 