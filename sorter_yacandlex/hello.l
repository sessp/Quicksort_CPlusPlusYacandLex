%{
#include <stdio.h>
#include "y.tab.h"
#include <string.h>
%}
INT [0-9]+
COMMA \,

%%
exit    exit(0);
(\[({INT}{COMMA}|{INT})*\])  yylval.list=strdup(yytext); return UNSORTEDLIST;

" " | \t  | \n  ;
%%
//Control+D to end the program.