struct Entry 
{ 
	char domain[20];
	char address[10][16];
	int count;
	struct Entry* next; 
}; 

int searchDomain(struct Entry* head, char *domain)
{
	struct Entry *temp = head;
	if (head == NULL) 
	{
		return 0;
	}
	while (temp != NULL) 
	{
		if(strcmp(temp->domain, domain) == 0)
		{
			return 1;
		}
		temp = temp->next;
	}
	return 0;
}

int searchAddress(struct Entry* head, char *address) 
{ 
	struct Entry *temp = head;
	if (head == NULL) 
	{
		return 0;
	}
	while (temp != NULL) 
	{
		for(int i = 0; i < temp->count; i++)
		{
			if(strcmp(temp->address[i], address) == 0)
			{
				return 1;
			}
		}
		temp = temp->next;
	}
	return 0;
}

int checkIP(char *address)
{
	int count = 0;
	int num[5];
	for(int i = 0; i < strlen(address); i++)
	{
		if(address[i] == '.')
		{
			count++;
		}
	}
	
	if(count != 3)
	{
		return 1;
	}
	count = 0;
	char value[10];
	strcpy(value, "");
	
	for(int i = 0; i < strlen(address); i++)
	{
		if(address[i] == '.')
		{
			num[count++] = atoi(value);
			strcpy(value, "");
		}
		else
		{
			strncat(value, &address[i], 1); 
		}
	}
	
	num[count++] = atoi(value);
	
	for(int i = 0; i < count; i++)
	{
		if(num[i] < 0 || num[i] > 255)
		{
			return 1;
		}
	}
	return 0;
}

void modifyEntry(struct Entry** head, char *domain, char* address) 
{ 
	struct Entry* current = *head;  // Initialize current 
	if(searchAddress(*head, address) == 1)
	{
		printf("Address already present!\n");
		return;
	}
	while (current != NULL) 
	{ 
		if (strcmp(current->domain, domain) == 0)
		{
			strcpy(current->address[current->count++], address);
			return;
		}
		current = current->next; 
	} 
}

int addEntry(struct Entry** head, char *domain, char *address) 
{   

	if(checkIP(address) == 1)
	{
		printf("Invalid IP address!\n");
		return 0;
	}
	if(searchAddress(*head, address) == 1)
	{
		printf("Address already present!\n");
		return 0;
	}
	if(searchDomain(*head, domain) == 1)
	{
		modifyEntry(head, domain, address);
		return 1;
	}
	
	struct Entry* new_Entry = (struct Entry*) malloc(sizeof(struct Entry));   
	struct Entry *last = *head;
  	
	strcpy(new_Entry->domain, domain);
	new_Entry->count = 0;
	strcpy(new_Entry->address[new_Entry->count++], address);
  
	new_Entry->next = NULL; 
  
	if (*head == NULL) 
	{ 
		*head = new_Entry; 
		return 1; 
	} 
  
	while (last->next != NULL) 
		last = last->next; 
  
	last->next = new_Entry; 
	return 1; 
}


char* getAddress(struct Entry* head, char *domain) 
{ 
	static char address[100];
	strcpy(address, "");;
	
	if (head == NULL) 
	{
		printf("List is empty.\n");
		return NULL;
	}
	struct Entry *temp = head;
	while (temp != NULL) 
	{
		if(strcmp(temp->domain, domain) == 0)
		{
			for(int i = 0; i < temp->count; i++)
			{				
				strcat(address, temp->address[i]);

				if((temp->count - i) != 1)
				{
					strcat(address, " ");
				}
			}
			break;
		}
		temp = temp->next;
	}
	return address;
} 

void printTable(struct Entry *head) {
	struct Entry *temp;
	if (head == NULL) {
		printf("List is empty.\n");
		return;
	}
	//printf("Server domain\t\tIP address\n");
	printf("+-------------------+----------------------+\n");
	printf("|   Server Domain   |      IP Address      |\n");
	printf("+-------------------+----------------------+\n");
	temp = head;
	while (temp != NULL) {
		printf("| %-17s ", temp->domain);
		for(int i = 0; i < temp->count; i++)
		{
			printf("| %-20s |\n", temp->address[i]);
			if((temp->count - i) != 1)
			{
				printf("|\t\t    ");
			}
		}
		printf("+-------------------+----------------------+\n");
		temp = temp->next;
	}
	printf("\n");

}

