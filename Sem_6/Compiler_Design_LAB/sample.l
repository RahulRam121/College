%{
#include <stdio.h>
%}
digit [0-9]+
%%
$digit+(.digit+)? { printf("%s\n", yytext); }
.|\n   { }
%%
main()
{ yylex();
}
int yywrap(){return(1);}
