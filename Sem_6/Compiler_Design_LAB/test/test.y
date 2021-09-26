%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "y.tab.h"
void yyerror(char* str);
int yylex(void);
int t = 1;
void buildTAC(int a, char op[], int b);
char resultStr[100];
char temp[20];
%}
%union{
    char dval;
}

%type <dval> Expr
%type <dval> E
%token id
%left '+' '-'
%left '*' '/'
%left '^'
%left '(' ')'
%left '!' '&&' '||'
%left '>>' '<<'

%%
Expr: E {
		printf("Result is %s\n", $$);
		return 0;
		};
//E:	E '+' E {$$ = $1 + $3;buildTAC($1, "+", $3);}
//	| E '-' E {$$ = $1 - $3;buildTAC($1, "-", $3);}
//	|E'*'E {$$=$1*$3;buildTAC($1, "*", $3);} 
//	|E'/'E {$$=$1/$3;buildTAC($1, "/", $3);} 
//	|E'^'E {$$=pow($1,$3);buildTAC($1, "^", $3);}
//	|'('E')' {$$=$2;} 
//	|E'&&'E {$$=$1&&$3;buildTAC($1, "&&", $3);}
//	|E'||'E {$$=$1||$3;buildTAC($1, "||", $3);}
//	|'!'E {$$=!$2;}
//	|E'<<'E {$$=$1<<$3;buildTAC($1, "<<", $3);}
//	|E'>>'E {$$=$1>>$3;buildTAC($1, ">>", $3);}
E:	E '+' E {sprintf($$,"t = %d + %d", $1, $2);printf("%s\n", $$);}
	| id {$$=$1;} 
; 
	

%%
void yyerror(char *str)
{ 
   fprintf(stderr,"%s\n",str);
} 

void buildTAC(int a, char op[], int b) {
	strcpy(temp, "");
	sprintf(temp, "t%d = %d %s %d\n", t, a, op, b);
	strcat(resultStr, temp);
	t++;
}

void main() 
{ 
	for(int i=0;i<5;i++){
		printf("Enter Expression:");
		yyparse(); 
		printf("%s\n", resultStr);
	}
	
	exit(0);
} 
