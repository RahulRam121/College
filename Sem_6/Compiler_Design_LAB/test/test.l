%{
#include<stdio.h>
#include<stdlib.h>
#include "y.tab.h"
void yyerror(char*);
extern int yylval;
%}

num [0-9]+
op "+"|"-"|"*"|"/"|"^"|"<<"|">>"|"||"|"&&"|"%"|"!"
paran "("|")"

%%
{num}	{yylval.dval=yytext; return id;}
{op}	return *yytext;
{paran} return *yytext;
[\t]	;
[\n]	return 0;
.		{yyerror("Invalid input in the expression!"); exit(1);}
%%

int yywrap(void) {
	return 1;
}


