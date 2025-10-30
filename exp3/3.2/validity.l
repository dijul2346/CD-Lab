%{
  #include<stdlib.h>
  #include "validity.tab.h"
%}
%%
[0-9]* {return NUMBER;}
[a-zA-Z][a-zA-Z0-9]* {return IDENTIFIER;}
\n  {return 0;}
[\t] ;
. {return yytext[0];}
%%
int yywrap()
{
   return 1;
}