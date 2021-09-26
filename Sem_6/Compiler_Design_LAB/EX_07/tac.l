%{
#include<stdio.h> 
#include<string.h> 
#include "y.tab.h"
%}

term ([a-zA-Z\_][a-zA-Z\_0-9]*|[0-9]+)
relop ("<"|"<="|">"|">="|"=="|"!=")
op ("+"|"-"|"*"|"/"|"%")

%%
"while" { return WHILE; } 
"do" { return DO; }
"switch" { return SWITCH; }
"case" { return CASE; }
"default" { return DEFAULT; }
"break" { return BREAK; }
{term} { yylval.str = strdup(yytext); return TERM; }
{relop} { yylval.str = strdup(yytext); return RELOP; }
{op} { yylval.str = strdup(yytext); return OP; } 
[ \t\n]+ { }
. { return *yytext; }
%%

int main(int argc,char **argv)
{
	FILE *fp; 
	fp = fopen(argv[1],"r"); 
	if (fp == NULL)
	{
		printf("FILE NOT FOUND!!\n");
		exit(1);
	}
    fp = fopen(argv[1],"r");
	yyin = fp;
	yyparse(); 
	return 0;
}

