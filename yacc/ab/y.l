%{
    #include "y.tab.h"
%}

%%
a {return 'a';}
b {return 'b';}
\n {return '\n';}
.
%%

int yywrap(void){
    return 1;
}