%{
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"y.tab.h"
int yylex(void);
void yyerror(char *str);

%}


%token id 
  
%left '+' '-' 
  
%left '*' '/'
  
%left '^'

%left '(' ')'

%left '!' '&&' '||'

%left '>>' '<<'


%%

Expr: E {
	printf("Result is %d\n\n", $$); 
	return 0; 
	}; 

E:	E'+'E {$$=$1+$3;} 

	|E'-'E {$$=$1-$3;} 

	|E'*'E {$$=$1*$3;} 

	|E'/'E {$$=$1/$3;} 

	|E'^'E {$$=pow($1,$3);}

	|'('E')' {$$=$2;} 

	|E'&&'E {$$=$1&&$3;}

	|E'||'E {$$=$1||$3;}

	|'!'E {$$=!$2;}

	|E'<<'E {$$=$1<<$3;}

	|E'>>'E {$$=$1>>$3;}

	| id {$$=$1;} 

; 
  
%%
  
 
void yyerror(char *str)
{ 
   fprintf(stderr,"%s\n",str);
   continue;
} 


void main() 
{ 
	for(int i=0;i<5;i++){
		printf("Enter Expression:");
		yyparse(); 
		
	}
	exit(0);
} 
