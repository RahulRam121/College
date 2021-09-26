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

struct Node* createProductionList()
{
	struct Node *head = NULL;
	char NT[3];
	char eq[30];
	int start = -1;
	char delim[] = " ";
	
	FILE *file = fopen ("input.txt", "r");  

	while (fgets(eq, 30, file))
	{
		// remove newline
		eq[strcspn(eq, "\n")] = 0;
		
		// get NT's
		for(int i = 0; i < strlen(eq); i++) 
		{
			if(eq[i] == '=') 
			{
				strcpy(NT, getSubString(eq, 0, i-1));
				start = i+1;
				break;
			}
		}
	
		for(int i = start; i < strlen(eq); i++)
		{
			if(eq[i] == '|')
			{
				char temp[20];
				char prod[10][5];
				int size = 0;
				strcpy(temp, getSubString(eq, start, i-1));
				char *ptr = strtok(temp, delim);
				
				while(ptr != NULL)
				{
					strcpy(prod[size++], ptr);
					ptr = strtok(NULL, delim);
				}
				addProduction(&head, NT, prod, size);
				start = i+1;
			}
		}
		if(start < strlen(eq))
		{
			char temp[20];
			char prod[10][5];
			int size = 0;
			strcpy(temp, getSubString(eq, start, strlen(eq)-1));
			char *ptr = strtok(temp, delim);
			
			while(ptr != NULL)
			{
				strcpy(prod[size++], ptr);
				ptr = strtok(NULL, delim);
			}
			addProduction(&head, NT, prod, size);
		}
		
	}
	
	return head;
}

int main() 
{
	FILE *file = fopen ("input.txt", "r");  
	char inputstring[30];
	char strings[10][5];
	char NTs[10][5];
	int nt_size;
	int size = 0;
	struct Node *head = createProductionList();
	struct Stack *stack = NULL;
	int index = 1;
	
	// get string of non Terminals
	struct Node *current = head;
	while (current != NULL) 
    { 
		strcpy(NTs[nt_size++], current->NT);
        current = current->next; 
    } 
	
	//printf("Enter input string: ");
	//scanf("%s", string);
	strcpy(inputstring, "id + id * id");
	
	//converting string to string array
	char *ptr = strtok(inputstring, " ");			
	while(ptr != NULL)
	{
		strcpy(strings[size++], ptr);
		ptr = strtok(NULL, " ");
	}
	
	
	
	
	stack.push(strings[0]);
	
	while(!isEmpty(stack))
	{
		char NT[5];
		strcpy(NT, pop(stack));
		
		struct Node* current = head;  
	    while (current != NULL) 
	    { 
	        if (strcmp(current->NT, NT) == 0) 
	            return true; 
	        current = current->next; 
	    } 
	}
	
	
	
	//printProductions(head);
	
}

