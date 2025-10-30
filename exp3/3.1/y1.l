%{
    #include<stdio.h>
    #include "y.tab.h"
%}

%%

[a-zA-Z][a-zA-Z0-9_]* {return IDENTIFIER;}
\n {return NEWLINE;}
.

%%

int yywrap(){
    return 1;
}