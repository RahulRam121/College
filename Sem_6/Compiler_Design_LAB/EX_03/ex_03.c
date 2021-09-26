//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <stdbool.h>
//
//char new_productions[20][15];
//int num_newproducions = 0;
//
//char* getSubString(char line[], int start, int stop)
//{
//	int length = stop - start + 1;
//	char *sub = (char*)malloc(sizeof(char) * (length + 1));
//	
//	int c = 0;
//	while (c < length) {	
//      sub[c] = line[start+c];
//      c++;
//   	}
//   	sub[c] = '\0';
//   	return sub;
//}
//
//void eliminateLeftRecursion(char eq[])
//{
//	char NT = eq[0];
//	char productions[10][15];
//	int num = 0, start = 2;
//	
//	// extracting right productions and placing it in string array
//	for(int i = 2; i < strlen(eq); i++)
//	{		
//		if(eq[i] == '|')
//		{
//			strcpy(productions[num++], getSubString(eq, start, i-1));			
//			start = i + 1;
//		}
//	}
//	if(start < strlen(eq))
//	{
//		strcpy(productions[num++], getSubString(eq, start, strlen(eq)-1));
//	}
//	
//	// checking for left recursion
//	bool isleftrecursive = false;
//	for(int i = 0; i < num; i++)
//	{
//		if(NT == productions[i][0])
//		{
//			isleftrecursive = true;
//			break;
//		}
//	}	
//	
//	if(!isleftrecursive)
//	{
//		printf("%s\n", eq);
//		//strcpy(new_productions[num_newproductions], %s);
//		return;
//	}
//	
//	// eliminating left recursion
//	bool terminal = false, isFirst = true;
//	printf("%c=", NT);
//	for(int i = 0; i < num; i++)
//	{
//		if(NT != productions[i][0])
//		{
//			if(!isFirst)
//			{
//				printf("|");
//			}
//			else
//			{
//				isFirst = false;
//			}
//			printf("%s%c\'", productions[i], NT);
//			terminal = true;
//		}
//	}
//	
//	
//	if(!terminal)
//	{
//		printf("%c'\n", NT);
//	}
//	else
//	{
//		printf("\n");
//	}
//	
//	printf("%c'=", NT);
//	isFirst = true;
//	for(int i = 0; i < num; i++)
//	{
//		if(NT == productions[i][0])
//		{
//			if(!isFirst)
//			{
//				printf("|");
//			}
//			else
//			{
//				isFirst = false;
//			}
//			printf("%s%c\'", getSubString(productions[i], 1, strlen(productions[i])-1), NT);
//		}
//	}
//	
//	printf("|e\n");
//	
//}
//
//int main() 
//{
//	FILE *file = fopen ("input.txt", "r");  
//	char eq[30];
//	while (fgets(eq, 30, file))
//	{
//		eq[strcspn(eq, "\n")] = 0;
//		eliminateLeftRecursion(eq);
//	}
//	
//}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "list.h"


char* getSubString(char line[], int start, int stop)
{
	int length = stop - start + 1;
	char *sub = (char*)malloc(sizeof(char) * (length + 1));
	
	int c = 0;
	while (c < length) {	
      sub[c] = line[start+c];
      c++;
   	}
   	sub[c] = '\0';
   	return sub;
}

struct Node* eliminateLeftRecursion(char eq[])
{
	char NT = eq[0];
	char NTs[3];
	char productions[10][15];
	int num = 0, start = 2;
	char dash = '\'';
	struct Node *head = NULL;
	
	// extracting right productions and placing it in string array
	for(int i = 2; i < strlen(eq); i++)
	{		
		if(eq[i] == '|')
		{
			strcpy(productions[num++], getSubString(eq, start, i-1));			
			start = i + 1;
		}
	}
	if(start < strlen(eq))
	{
		strcpy(productions[num++], getSubString(eq, start, strlen(eq)-1));
	}
	
	// checking for left recursion
	bool isleftrecursive = false;
	for(int i = 0; i < num; i++)
	{
		if(NT == productions[i][0])
		{
			isleftrecursive = true;
			break;
		}
	}	
	
	strcpy(NTs, "");
	strncat(NTs, &NT, 1);
	
	if(!isleftrecursive)
	{
		//printf("%s\n", eq);
		
		for(int i = 0; i < num; i++)
		{
			addProduction(&head, NTs, productions[i]);
		}
		return head;
	}
	
	// eliminating left recursion
	bool terminal = false;
	//printf("%c=", NT);
	for(int i = 0; i < num; i++)
	{
		if(NT != productions[i][0])
		{
			//printf("%s%c\'", productions[i], NT);
			strncat(productions[i], &NT, 1);
			strncat(productions[i], &dash, 1);
			addProduction(&head, NTs, productions[i]);
			terminal = true;
		}
	}
	
	
	if(!terminal)
	{
		//printf("%c'\n", NT);
		char temp[10];
		strcpy(temp, "");
		strncat(temp, &NT, 1);
		strncat(temp, &dash, 1);
		addProduction(&head, NTs, temp);
	}
	
	strncat(NTs, &dash, 1);
	//printf("%c'=", NT);
	for(int i = 0; i < num; i++)
	{
		if(NT == productions[i][0])
		{
			char temp[10];
			strcpy(temp, getSubString(productions[i], 1, strlen(productions[i])-1));
			strncat(temp, &NT, 1);
			strncat(temp, &dash, 1);
			addProduction(&head, NTs, temp);
			//printf("%s%c\'", getSubString(productions[i], 1, strlen(productions[i])-1), NT);
		}
	}
	
	//printf("|e\n");
	addProduction(&head, NTs, "e");
	
	return head;
}

int main() 
{
	FILE *file = fopen ("input.txt", "r");  
	char eq[30];
	struct Node *head = NULL;
	while (fgets(eq, 30, file))
	{
		eq[strcspn(eq, "\n")] = 0;
		struct Node *temp = eliminateLeftRecursion(eq);
		while(temp != NULL) 
	   	{
	    	addProduction(&head, temp->NT, temp->production);
	      	temp = temp->next;
	   	}
		
	}
	printProductions(head);
	
}

