struct Node 
{ 
  char NT[3]; 
  char production[10];
  struct Node *next; 
};

void addProduction(struct Node** head_ref, char NT[], char production[]) 
{ 
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
  
    struct Node *last = *head_ref; 

    strcpy(new_node->NT,NT);
    strcpy(new_node->production, production);
  
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
    	printf("%s -> %s\n", ptr->NT, ptr->production);
      	ptr = ptr->next;
   	}
   	printf("\n");
}
