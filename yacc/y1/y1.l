%{
    #include<stdio.h>
    #include "y1.tab.h"
%}

%%
[a-zA-Z][a-zA-Z0-9_]* {return IDENTIFIER;}
[\n] {return NEWLINE;}
[ \t] ;
. {return INVALID;}

%%
int yywrap(){
    return 1;
}