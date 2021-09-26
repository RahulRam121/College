#include<stdio.h>
#include<string.h>
#include<ctype.h>
char productions[10][5];
int index = 0, size = 0, error = 0;
void Eprime();
void T();
void Tprime();
void F();
void E()
{
	if(error == 0)
	{
		printf("T() ");
	}
	printf("E() ");
	T();
	Eprime();
}
void Eprime()
{
	if(error == 0)
	{
		printf("T() ");
	}
	printf("E'() ");
	if(strcmp(productions[index],"+") == 0)
	{
		index++;
		T();
		Eprime();
	}
} 
void T()
{
	if(error == 0)
	{
		printf("T() ");
	}
	
	F();
	Tprime();
} 
void Tprime()
{
	if(error == 0)
	{
		printf("T'() ");
	}
	
	if(strcmp(productions[index], "*") == 0)
	{
		index++;
		F();
		Tprime();
	}
}
void F()
{
	if(error == 0)
	{
		printf("F() ");
	}
	
	if(strcmp(productions[index], "id") == 0)
	{
		index++;
	}
	else if(strcmp(productions[index], "(") == 0)
	{
		index++;
		E();
		if(strcmp(productions[index], ")") == 0)
        {
           index++;
        }
		else
		{
			error = 1;
			printf("Error! ");
			return;
		}		
	}
	else
	{
		error=1;
		printf("Error! ");
		return;
	}
		
}
	
void main()
{
	
	char inputstring[30];
	char temp[30];
	
	printf("Enter input string: ");
	scanf("%[^\n]%*c",inputstring);
	
	strcpy(temp, inputstring);
	
	char *ptr = strtok(temp, " ");			
	while(ptr != NULL)
	{
		strcpy(productions[size++], ptr);
		ptr = strtok(NULL, " ");
	}

	E();
	if(size == index && error == 0)
	{
		printf("\n%s is accepted\n", inputstring);
	}
	else
	{
		printf("\n%s is rejected\n", inputstring);
	}

	
}
