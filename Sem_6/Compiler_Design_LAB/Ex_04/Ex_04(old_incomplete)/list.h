struct Node 
{ 
  char NT[3]; 
  char production[10][5];
  int size;
  struct Node *next; 
};

void addProduction(struct Node** head_ref, char NT[], char production[10][5], int size) 
{ 
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
  
    struct Node *last = *head_ref; 

    strcpy(new_node->NT,NT);
    new_node->size = size;
    for(int i = 0; i < size; i++)
    {
    	strcpy(new_node->production[i], production[i]);
	}
  
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

//bool search(struct Node* head, char variable[]) 
//{ 
//    struct Node* current = head; 
//    
//    while (current != NULL) 
//    { 
//        if (strcmp(current->variable, variable) == 0) 
//            return true; 
//        current = current->next; 
//    } 
//    return false; 
//}

void printProductions(struct Node *ptr) 
{
	printf("New Productions\n");
	while(ptr != NULL) 
   	{
    	printf("%s -> ", ptr->NT, ptr->size);
    	for(int i = 0; i < ptr->size; i++) 
    	{
    		printf("%s ", ptr->production[i]);
		}
		printf("\n");
      	ptr = ptr->next;
   	}
   	printf("\n");
}
