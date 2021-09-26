#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Node{
	int start, end;
	int size;
	char status[3];
	struct Node* next;
};

void addNode(struct Node** head_ref, int start, int end, char status[]);
int size(struct Node* node);
void memoryRepresentation(struct Node* node);
void printMenu1();
void printMenu2();
char* findStatus(struct Node* node, int index);
int findIndex(struct Node* node, char id[]);
int firstFit(struct Node* node, int rsize);
int bestFit(struct Node* node, int rsize);
int bestFit(struct Node* node, int rsize);
void allocateMemory(struct Node** alloc, struct Node** free, struct Node** phy, int index, int nsize, char id[]);

void allocateMemory(struct Node** alloc, struct Node** free, struct Node** phy, int index, int nsize, char id[]){
	
	int i = 0;
	struct Node* node = *phy;
	for(int i = 0; i < index; i++){
		node = node->next;
	}
	addNode(alloc, node->start, node->end, id);
	
	int new_index = findindex2(free, node->start, node->end);
	
	node = *
	
	
}

int worstFit(struct Node* node, int rsize){
	int max = 0, count = 0, index = -1;
	while(node != NULL){
		if(node->size > rsize){
			if((node->size - rsize) > max){
				max = node->size - rsize;
				index = count;
			}
		}
		count++;
		node = node->next;
	}
	return index;
}

int bestFit(struct Node* node, int rsize){
	int min = 10000, count = 0, index = -1;
	while(node != NULL){
		if(node->size > rsize){
			if((node->size - rsize) < min){
				min = node->size - rsize;
				index = count;
			}
		}
		count++;
		node = node->next;
	}
	return index;
}

int firstFit(struct Node* node, int rsize){
	int count = 0;
	while(node != NULL){
		if(node->size > rsize){
			return count;
		}
		count++;
		node = node->next;
	}
	return -1;
}

int findIndex(struct Node* node, char id[]){
	int index = 0;
	
	while(node != NULL){
		if(strcmp(id, node->status) == 0)
			return index;
		index++;
		node = node->next;
	}
	printf("Not found!\n");
	return -1;
}

int findIndex2(struct Node* node, int start, int end){
	int index = 0;
	
	while(node != NULL){
		if(node->start == start && node->end == end)
			return index;
		index++;
		node = node->next;
	}
	printf("Not found!\n");
	return -1;
}

char* findStatus(struct Node* node, int index){
	
	for(int i = 0; i < index; i++){
		node = node->next;
	}
	return node->status;
}

int size(struct Node* node){
	int size = 0;
	while(node != NULL){
		size++;
		node = node->next;
	}
	return size;
}

void printMenu1(){
	
	printf("Memory Allocation Algorithm\n1.First Fit\n2.Best Fit\n3.Worst Fit\n4.Exit from program\nEnter choice : ");
}

void printMenu2(){
	
	printf("1.Entry/Allocate\n2.Exit/Deallocate\n3.Display\n4.Coalescing of Holes\n5.Back to Algorithm\nEnter choice : ");
}

void addNode(struct Node** head_ref, int start, int end, char status[]) { 

    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
    struct Node *last = *head_ref;
  
    new_node->start  = start; 
    new_node->end = end;
    new_node->size = end - start;
    strcpy(new_node->status,status);
    
    new_node->next = NULL; 
  
    if (*head_ref == NULL) { 
       *head_ref = new_node;        
       return; 
    } 
  	
    while (last->next != NULL) 
        last = last->next; 
  
    last->next = new_node; 
    return; 
}

void memoryRepresentation(struct Node* node) { 

	struct Node* head = node;
	int totalSize = 0;
	int dashes;
	int spaces = 0;
	int n = size(node);
	
    while (head != NULL) { 
        totalSize += head->size;    
		head = head->next;
    } 
    
    dashes = (totalSize * 2) + n + 1;
    
    printf("\n");
    for(int i = 0; i < dashes; i++){
    	printf("-");
	}
	printf("\n|");
	
	head = node;
	
	while(head != NULL){
		if(head->end != head->start){
			printf("%s",head->status);
		
			spaces = (2 * (head->size-1));
			if(strcmp(head->status,"H") == 0)
				 spaces++;
			
			for(int i = 0; i < spaces; i++){
				printf(" ");
			}
			printf("|");	
		}
		else
			printf("|");
				
		head = head->next;
		spaces = 0;
	}
	
	printf("\n");
	
	for(int i = 0; i < dashes; i++){
    	printf("-");
	}
	printf("\n");
	
	head = node;
	
	while(head != NULL){
		spaces = 0;
		if(head->end != head->start){
			printf("%d",head->start);
			spaces = (head->size * 2) - 2;
		
			for(int i = 0; i < spaces; i++){
				printf(" ");
			}			
		}	
		
		if(head->next == NULL)
			printf("%d\n\n",head->end);
		head = head->next;
	}
	
    
} 

int main(){
	int partitions;
	int choice1 = 1;
	int choice2;
	
	struct Node* allottedMem = NULL;
	struct Node* freePool = NULL;
	struct Node* phyMem = NULL;
	
	printf("Enter the Memory Representation:\n");
	printf("Enter the number of partitions in memory: ");
	scanf("%d",&partitions);	
	
	for(int i = 0; i < partitions; i++){
		int start, end;
		printf("Starting and ending address of partition %d: ",i+1);
		scanf("%d %d",&start,&end);
		addNode(&freePool, start, end, "H");
		addNode(&phyMem, start, end, "H");		
	}
		
	
	while(choice1 != 4){
		
		printMenu1();
		scanf("%d",&choice1);	
		
		switch(choice1){
			
			choice2 = 1;
			
			case 1:{
				while(choice2 != 5){
					
					printMenu2();
					scanf("%d",&choice2);
					
					switch(choice2){												
						case 1:{
							int size;
							char id[3];
							int index;
							printf("Enter process id: ");
							scanf("%s",id);
							printf("Enter size needed: ");
							scanf("%d",&size);
							index = firstFit(phyMem, size);
							allocateMemory(&allottedMem, &freePool, &phyMem, index, size, id);
							break;
						}						
						case 2:{
							
							break;
						}						
						case 3:{
							
							break;
						}						
						case 4:{
							
							break;
						}						
						case 5:{
							printf("Exiting First Best Memory Allocation Algorithm\n");
							break;
						}						
						default:printf("Invalid Input!\n");
					}
				}
				break;
			}
			
			case 2:{
				
				break;
			}
			case 3:{
				
				break;
			}
			case 4:{
				printf("Program Terminated Succesfully!\n");
				break;
			}
			default:printf("Invalid Input!\n");
		}
	}
	
	

	memoryRepresentation(allottedMem);
	//memoryRepresentation(phyMem, partitions);
	
	return 0;
}
