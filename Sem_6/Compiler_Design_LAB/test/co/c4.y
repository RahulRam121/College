%{
	#include"y.tab.h"
	#include<stdio.h>
	#include<stdlib.h>
	#include<ctype.h>
	#include<math.h>
	int yyin(void);
	char temp ='A'-1;
	int index = 0;
	char label[6];
	char reg[6][4];
	char createTAC(char, char, char);
	void printTAC();
	void genCode();
	int checkLabel(char a,int n);
	struct expr{
		char op1;
		char op2;
		char op;
		char result;
	};
%}

%union{
	char symbol;
}

%left '+''-'
%left '*''/'
%left '^'


%token <symbol> NUMBER ID
%type <symbol> E

%%
line : stmt line | stmt
stmt: ID '=' E  {createTAC((char)$1,(char)$3,'=');};
E: E '+' E {$$ = createTAC((char)$1,(char)$3,'+');}
    |E '-' E {$$ = createTAC((char)$1,(char)$3,'-');}
    |E '/' E {$$ = createTAC((char)$1,(char)$3,'/');}
    |E '*' E {$$ = createTAC((char)$1,(char)$3,'*');}
    |E '^' E {$$ = createTAC((char)$1,(char)$3,'^');}
    |'(' E ')' {$$ = (char)$2;}
    |NUMBER {$$ = (char)$1;}
    |ID {$$=(char)$1;};
%%

struct expr arr[20];

void printTAC(){
    int i;
    for(i=0;i<index;i++){
        if(arr[i].op=='!') continue;
        printf("%c  :=  ",arr[i].result);
        printf("%c  ",arr[i].op1);
        printf("%c  ",arr[i].op);
        printf("%c\n",arr[i].op2);
    }
}


int yywrap(){
    return 1;
}

void yyerror(char *s){
    printf("Error %s",s);
    exit(1);
}

char createTAC(char a, char b, char c){
    temp++;
    arr[index].op1=a;
    arr[index].op2=b;
    arr[index].op=c;
    arr[index].result=temp;
    index++;
    return temp;
}

void optimization() {
	int i, j;
	int a, b, c;
	int change = 1;
	while(change == 1) {
		change = 0;
		for(i = 0; i < index; i++) {
			if(isdigit(arr[i].op1) && isdigit(arr[i].op2)) {
				change = 1;
				a = arr[i].op1 - '0';
				b = arr[i].op2 - '0';
				if(arr[i].op == '+') {
					c = a + b;
				}
				else if(arr[i].op == '-') {
					c = a - b;
				}
				else if(arr[i].op == '*') {
					c = a * b;
				}
				else if(arr[i].op == '/') {
					c = a / b;
				}
				else if(arr[i].op == '^'){
					c = pow(a,b);
				}
				else {
					change = change == 1 ? 0 : 1;
				}
				if(change == 1) {
					for(j=i+1;j<index;j++){
				    	if(arr[j].op1==arr[i].result) arr[j].op1= c+'0';
				        if(arr[j].op2==arr[i].result) arr[j].op2= c+'0';
					}
				}
			    arr[i].op = '!';
			}
			if(!isdigit(arr[i].op1) && isdigit(arr[i].op2) && arr[i].op == '=') {
				
				for(j=i+1;j<index;j++){
			    	if(arr[j].op1==arr[i].op1 && arr[j].op != '=') {
						arr[j].op1= arr[i].op2;
						arr[i].op = '!';
						change = 1;
					}
			        if(arr[j].op2==arr[i].op1 & arr[j].op != '=') {
			        	arr[j].op2= arr[i].op2;
			        	arr[i].op = '!';
			        	change = 1;
			    	}
				}
			}
		}
	}
}

int checkLabel(char a,int n) {
	int i;
	for(i=0; i < a; i++) {
		if(a == label[i]) return 1;
	}
	return 0;
}

void genCode() {
	int start = 0, i;
	char r0 = 'A';
	
	for(i=0;i<index;i++){
    	if(!isdigit(arr[i].op1) && isdigit(arr[i].op2) && arr[i].op == '=') {
			printf("MOV #%c, %c\n", arr[i].op2, arr[i].op1);
		}
		else if(arr[i].op != '=') {
			if(arr[i].op1 != r0 && arr[i].op2 != r0) {
				if(arr[i].op == '^') printf("MOV %c, R0\nPOW %c, R0\n", arr[i].op2, arr[i].op1);
				if(arr[i].op == '+') printf("MOV %c, R0\nADD %c, R0\n", arr[i].op2, arr[i].op1);
				if(arr[i].op == '-') printf("MOV %c, R0\nSUB %c, R0\n", arr[i].op2, arr[i].op1);
				if(arr[i].op == '*') printf("MOV %c, R0\nMUL %c, R0\n", arr[i].op2, arr[i].op1);
				if(arr[i].op == '/') printf("MOV %c, R0\nDIV %c, R0\n", arr[i].op2, arr[i].op1);
			}
		}
		else {
			printf("MOV R0, %c\n",arr[i].op1);
		}
	}
	
}

