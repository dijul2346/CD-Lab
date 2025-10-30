%{
#include "paren.tab.h"
%}

%%
"("     { return '('; }
")"     { return ')'; }
\n      { return 0; }  // End of input
[ \t]   ;               // Ignore spaces
.       { return yytext[0]; } // Any other char
%%

int yywrap() { return 1; }
