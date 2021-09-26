%{
#include"y.tab.h"
extern char yyval;
%}

%%
[0-9]+ {
yylval.symbol = (char)yytext[0];
		printf("%c = Constant\n", yytext[0]);
		return NUMBER;
	}
	
[a-zA-Z]+ {
yylval.symbol =(char) yytext[0];
		printf("%c = Identifier\n", yytext[0]);
		return ID;
	}
	
["+"|"-"|"*"|"/"|"^"] {
		printf("%c = Operator\n", yytext[0]);
		return yytext[0];
	}
	
[ \t\n]+ { }

. {return yytext[0];}

%%
int main(){
    char temp='A'-1;
    char* t = "input.txt";
    FILE *fp; 
	fp = fopen(t,"r"); 
	if (fp == NULL)
	{
		printf("File not found error\n");
		exit(0);
	}
	yyin = fp;
	printf("Tokens : \n");
    yyparse();
    printf("Syntax Correct\n");
    printf("\nThree Adress Code before Optimization : \n");
    printTAC();
    optimization();
    printf("\nOptimized Three Address Code(using constant folding) : \n");
    printTAC();
    printf("\nCode generated : \n");
    genCode();

}
