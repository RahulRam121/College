%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	#include"y.tab.h"
	int yylex(void);
%}

%union{
    char dval;
}

%token <dval> NUM
%type <dval> E
%left '+' '-'
%left '*' '/' '%'

%%
statement : E {printf("");}
          ;

E : E '+' E 
    {   
        gencode($1,'+',$3);
        $$=getCode();

    }
  | E '-' E 
    {
        gencode($1,'-',$3);
        $$=getCode();
    }
  | E '%' E 
    {
        gencode($1,'%',$3);
        $$=getCode();
    }
  | E '*' E 
    {
		gencode($1,'*',$3);
        $$=getCode();
    }
  | E '/' E 
    {
        gencode($1,'/',$3);
        $$=getCode();
    }
  | '(' E ')' 
    {
    	strcpy($$, $2);
    }
  | NUM 
    {
        strcpy($$, $1);
    }
  ;
%%


