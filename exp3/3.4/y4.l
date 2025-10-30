%{
#include"aabb.tab.h"
%}
%%
a {return A;}
b {return B;}
\n {return NEWLINE;}
. {return INVALID;}
%%
int yywrap(){return 1;}
