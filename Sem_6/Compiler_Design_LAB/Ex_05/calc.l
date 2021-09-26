%{

#include<stdio.h>
#include<stdlib.h>
#include"y.tab.h"
void yyerror(char*);
extern int yylval;

%}

num [0-9]+
Op "+"|"-"|"*"|"/"|"%"|"^"|"&&"|"||"|"!"|">>"|"<<"
paran "("|")"

%%
{num} {yylval=atoi(yytext);return id;}

{Op} return *yytext;

{paran} return *yytext;

[\t] ;

[\n] return 0;

. {yyerror("Invalid Character in input!!!");exit(1);}
%%

int yywrap(void)
{
	return 1;
} 
