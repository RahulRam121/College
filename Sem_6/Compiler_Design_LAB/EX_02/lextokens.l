%{
	#include<stdio.h>
%}

digit [0-9]
letter [A-Za-z]
identifier {letter}({letter}|{digit})*
keywords auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while
fcalls {letter}+"(".*")"
single_line_comment "//".*
integer {digit}+
float {digit}+\.{digit}+
string \"({letter}|{digit})*\"
multiple_line_comment "/*"([^*])*"*/"
aop "+"|"-"|"*"|"/"|"%"
aaop "+="|"-="|"*="|"/="|"%="
lop "&&"|"||"|"!"
relop "<"|"<="|">"|">="|"=="|"!="
bitop "^"|"&"|"|"|"<<"|">>"
unop "-"|"++"|"--"
assop "="
spec ";"|","|"."|"["|"]"|"("|")"|"{"|"}"|"["|"]"
prepro #.*

%%
{integer} { printf("\n%30s - Integer Value",yytext); }
{keywords} { printf("\n%30s - Keyword",yytext);}
(if|while|for|sizeof|switch)/"(".*")" { printf("\n%30s - Keyword",yytext);}
{identifier} { printf("\n%30s - Identifier",yytext);}
{single_line_comment} { printf("\n%30s - Single line Comment",yytext);}
{float} { printf("\n%30s - Float Value",yytext); }
{string} { printf("\n%30s - String Value",yytext); }
{multiple_line_comment} { printf("\n%30s - Multiple line comment",yytext);}
{aop} { printf("\n%30s - Arithmetic Operators%s",yytext);}
{aaop} { printf("\n%30s - Arithmetic assignment operators",yytext);}
{lop} { printf("\n%30s - Logical operators",yytext);}
{relop} { printf("\n%30s - Relational operators",yytext);}
{bitop} { printf("\n%30s - Bitwise operators",yytext);}
{unop} { printf("\n%30s - Unary operators",yytext);}
{assop} { printf("\n%30s - Assignment operator",yytext);}
{spec} { printf("\n%30s - Special character",yytext);}
{fcalls} { printf("\n%30s - Function calls",yytext);}
{prepro} { printf("\n%30s - Preprocessor Directive",yytext);}
.|\n { }
%%

void main(){
	FILE *f;
	f=fopen("test.c","r");
	yyin=f;
	yylex();
}
int yywrap(){return(1);}
