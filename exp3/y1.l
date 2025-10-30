%{
 #include<stdio.h>
 #include "y.tab.h"
%}
%%
[a-zA-Z_][a-zA-Z0-9_]* {return IDENTIFIER;}
\n			{return NEWLINE;}
[\t]			{/*ignore*/}
. ;		{return INVALID;}
%%
int yywrap()
{
  return 1;
}
