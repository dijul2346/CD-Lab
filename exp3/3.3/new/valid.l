%{
    #include "valid.tab.h"
    #include<stdio.h>
%}

%%
[0-9]+ {return NUMBER;}
[a-zA-Z]+ {return ID;}
[ \t\n] ;
.  ;

%%

int yywrap(){
    return 1;
}