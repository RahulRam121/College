struct table 
{
   char variable[30];
   char type[10];
   int bytes;
   int address;
   char value[10];
   struct table *next;
};

void printTable(struct table *ptr);
void addRow(struct table** head_ref, char variable[], char type[], int bytes, int address, char value[]);
bool isEmpty(struct table *head);
bool search(struct table* head, char variable[]);
void addValue(struct table* head, char variable[], char value[]);

void printTable(struct table *ptr) 
{
	printf("Content of Symbol Table:\n\n");
	printf("Identifier | Type       | Number of  | Address    | Value\n");
	printf("Name       |            | Bytes      |            |\n");
	printf("------------------------------------------------------------\n");
	
	while(ptr != NULL) 
   	{
    	printf("%-10s | %-10s | %-10d | %-10d | %s\n", ptr->variable, ptr->type, ptr->bytes, ptr->address, ptr->value);
      	ptr = ptr->next;
   	}
   	printf("\n");
}

void addRow(struct table** head_ref, char variable[], char type[], int bytes, int address, char value[]) 
{ 
    struct table* new_node = (struct table*) malloc(sizeof(struct table)); 
  
    struct table *last = *head_ref; 

    new_node->address = address;
    new_node->bytes = bytes;
    strcpy(new_node->variable, variable);
    strcpy(new_node->type, type);
    strcpy(new_node->value, value);
  
    new_node->next = NULL; 
  
    if (*head_ref == NULL) 
    { 
       *head_ref = new_node; 
       return; 
    } 

    while (last->next != NULL) 
        last = last->next; 

    last->next = new_node; 
    return; 
} 

bool isEmpty(struct table *head) 
{
   return head == NULL;
}

bool search(struct table* head, char variable[]) 
{ 
    struct table* current = head; 
    
    while (current != NULL) 
    { 
        if (strcmp(current->variable, variable) == 0) 
            return true; 
        current = current->next; 
    } 
    return false; 
}

void addValue(struct table* head, char variable[], char value[]) 
{ 
    struct table* current = head; 
    
    while (current != NULL) 
    { 
        if (strcmp(current->variable, variable) == 0) 
        {
        	strcpy(current->value, value);
        	break;
		}
            
        current = current->next; 
    }  
}

