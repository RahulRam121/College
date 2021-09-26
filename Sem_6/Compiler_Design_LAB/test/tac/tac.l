%{
    #include<stdio.h>
    #include <stdlib.h>
    #include<string.h>
    #include"y.tab.h"
    void yyerror(char* str);
    int k=1;
    char word[100];
    void gencode(char first,char op,char second);
    char* getCode();
%}

%%
[0-9]+ 	{
yylval.dval=yytext[0];
return NUM;
}

\n {return 0;}
. {return yytext[0];}
%%

void yyerror(char* str)
{
        printf("\n%s",str);
}

int yywrap()
{
    return 1;
}

void gencode(char first,char op,char second)
{
    char temp[20];
    strcpy(temp, "");
    sprintf(temp,"t%d = %d %c %d\n", k, first, op, second);
    strcat(word,temp);
    k++;
}

char* getCode() {
	char temp[10];
	sprintf(temp, "t%d", k-1);
	return &temp;
}


int main()
{
        yyparse();
        printf("%s\n", word);
        return 0;
}
