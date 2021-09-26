#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Node 
{ 
  int data; 
  struct Node *next; 
}; 

int findLFU(struct Node* node, int arr[], int start, int len){
	int min = 10000;
	int value;
	int count;
	
	while(node != NULL){
		count = 0;
		for(int i = 0; i < start; i++){
			if(node->data == arr[i]){
				count++;
			}
		}
		if(count < min){
			min = count;
			value = node->data;
		}
		node = node->next;
	}
	return value;
}

int findLRU(struct Node* node, int arr[], int start, int len){
	int min = 10000;
	int value;
	int count;
	
	while(node != NULL){
		count = 0;
		for(int i = start; i >= 0; i--){
			if(node->data == arr[i]){
				break;
			}
			count++;
		}
		if(start - count < min){
			min = start-count;
			value = node->data;
		}
		node = node->next;
	}
	return value;
}

int findOptimal(struct Node* node, int arr[], int start, int len){
	int max = -1;
	int count;
	int value;
	while(node != NULL){
		count = 0;
		for(int i = start; i < len; i++){
			if(node->data == arr[i]){				
				break;
			}		
			count++;		
		}
		if(count > max){
			max = count;
			value = node->data;
		}
		node = node->next;
	}
	return value;
}

void printString(int arr[], int len){
	printf("Reference String : ");
	for(int i = 0; i < len; i++){
		printf("%d ",arr[i]);
	}
	printf("\n\n");
}

void printTable(int** arr, int len, int width){
	for(int i = 0; i < width; i++){
		for(int j = 0; j < len; j++){
			if(arr[j][i] == -1)
				printf("   ");
			else
				printf(" %d ",arr[j][i]);
		}
		printf("\n");
	}
}

bool checkList(struct Node* node, int value){
	while(node != NULL){
		if(node->data == value)
			return true;
		node = node->next;
	}
	return false;
}

void copyList(struct Node* node, int** arr, int index, int len){
	for(int i = 0; i < len && node != NULL; i++){
		arr[index][i] = node->data;		
		node = node->next;
	}
}
  
void append(struct Node** head_ref, int new_data) {   
    
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));   
    struct Node *last = *head_ref; 
    new_node->data  = new_data; 
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

void replaceFrame(struct Node **head_ref, int key, int page){
	struct Node* temp = *head_ref;
	
	while(temp != NULL){
		if(temp->data == key){
			temp->data = page;
			return;
		}
		temp = temp->next;
	}
}

void printList(struct Node *node) { 
	while (node != NULL) { 
    	printf(" %d ", node->data); 
    	node = node->next; 
	} 
} 

int main(){
	int frames;
	int required;
	int pages[50];
	int numpages;
	int choice = 1;
	
	while(choice != 6){
		printf("\n1.READ INPUT\n2.FIFO\n3.OPTIMAL\n4.LRU\n5.LFU\n6.Exit\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:{
				char refstr[50], ch;
				printf("Enter the number of free frames: ");
				scanf("%d",&frames);
				printf("Enter the number of frames required by the process: ");
				scanf("%d",&required);
				if(frames < required){
					printf("Frames required by proecess is greater than the free frames!\n");
					break;
				}
				scanf("%c",&ch);
				printf("Enter the reference string: ");
				scanf("%[^\n]%*c", refstr);
				
				char* token = strtok(refstr, " ");
				numpages = 0;
				while(token != NULL){
					pages[numpages++] = atoi(token);
					token = strtok(NULL, " ");
				}

				break;
			}
			case 2:{
				printf("\t\tFIFO Page Replacement Algorithm\n\n");
				printString(pages, numpages);
				struct Node* fifo = NULL;
				int i;
				int last[required];				
				int count = 0;
				
				int **table = (int **)malloc(numpages * sizeof(int *));
				for (int r = 0; r < numpages; r++)
					table[r] = (int *)malloc(required * sizeof(int));
					
				for(int j = 0; j < numpages; j++){
					for(int k = 0; k < required; k++){
						table[j][k] = -1;
					}
				}
				
				int page_faults = 0;
				
				printf("Page ref->     memory     ->PF\n");
				
				for(i = 0; i < required; i++){
					page_faults++;
					append(&fifo, pages[i]);
					printf("%d -> ",pages[i]);
					printList(fifo);
					copyList(fifo, table, i, required);
					for(int j = (required-1)-i; j > 0; j--){
						printf(" - ");
					}
					printf(" -> %d\n",page_faults);
					last[i] = pages[i];
				}
				count = required;
				
				for(i = i; i < numpages; i++){
					printf("%d -> ",pages[i]);
					if(!checkList(fifo, pages[i])){
						replaceFrame(&fifo, last[0], pages[i]);
						copyList(fifo, table, count++, required);
						printList(fifo);
						page_faults++;
						printf(" -> %d\n",page_faults);
						for(int k = 0; k < required-1; k++)
							last[k] = last[k+1];
						last[required-1] = pages[i];
					}
					else{
						printList(fifo);
						printf(" -> -\n");
					}
					
				}
				printf("\n");
				printTable(table, count, required);
				printf("\n");
				printf("Total number of page faults : %d\n",page_faults);
				
				break;
			}
			case 3:{
				printf("\t\tOptimal Page Replacement Algorithm\n\n");
				printString(pages, numpages);
				struct Node* optimal = NULL;
				int i;
				int count = 0;
				
				int **table = (int **)malloc(numpages * sizeof(int *));
				for (int r = 0; r < numpages; r++)
					table[r] = (int *)malloc(required * sizeof(int));
					
				for(int j = 0; j < numpages; j++){
					for(int k = 0; k < required; k++){
						table[j][k] = -1;
					}
				}
				
				int page_faults = 0;
				
				printf("Page ref->     memory     ->PF\n");
				
				for(i = 0; i < required; i++){
					page_faults++;
					append(&optimal, pages[i]);
					printf("%d -> ",pages[i]);
					printList(optimal);
					copyList(optimal, table, i, required);
					for(int j = (required-1)-i; j > 0; j--){
						printf(" - ");
					}
					printf(" -> %d\n",page_faults);
				}

				count = required;
				
				for(i = i; i < numpages; i++){
					printf("%d -> ",pages[i]);
					if(!checkList(optimal, pages[i])){
						int val = findOptimal(optimal, pages, i, numpages);
						replaceFrame(&optimal, val, pages[i]);
						copyList(optimal, table, count++, required);
						printList(optimal);
						page_faults++;
						printf(" -> %d\n",page_faults);
					}
					else{
						printList(optimal);
						printf(" -> -\n");
					}
					
				}
				printf("\n");
				printTable(table, count, required);
				printf("\n");
				printf("Total number of page faults : %d\n",page_faults);
				break;
			}
			case 4:{
				printf("\t\tLRU Page Replacement Algorithm\n\n");
				printString(pages, numpages);
				struct Node* lru = NULL;
				int i;
				int count = 0;
				
				int **table = (int **)malloc(numpages * sizeof(int *));
				for (int r = 0; r < numpages; r++)
					table[r] = (int *)malloc(required * sizeof(int));
					
				for(int j = 0; j < numpages; j++){
					for(int k = 0; k < required; k++){
						table[j][k] = -1;
					}
				}
				
				int page_faults = 0;
				
				printf("Page ref->     memory     ->PF\n");
				
				for(i = 0; i < required; i++){
					page_faults++;
					append(&lru, pages[i]);
					printf("%d -> ",pages[i]);
					printList(lru);
					copyList(lru, table, i, required);
					for(int j = (required-1)-i; j > 0; j--){
						printf(" - ");
					}
					printf(" -> %d\n",page_faults);
				}

				count = required;
				
				for(i = i; i < numpages; i++){
					printf("%d -> ",pages[i]);
					if(!checkList(lru, pages[i])){
						int val = findLRU(lru, pages, i, numpages);
						replaceFrame(&lru, val, pages[i]);
						copyList(lru, table, count++, required);
						printList(lru);
						page_faults++;
						printf(" -> %d\n",page_faults);
					}
					else{
						printList(lru);
						printf(" -> -\n");
					}
					
				}
				printf("\n");
				printTable(table, count, required);
				printf("\n");
				printf("Total number of page faults : %d\n",page_faults);
				break;
			}
			case 5:{
				printf("\t\tLFU Page Replacement Algorithm\n\n");
				printString(pages, numpages);
				struct Node* lfu = NULL;
				int i;
				int count = 0;
				
				int **table = (int **)malloc(numpages * sizeof(int *));
				for (int r = 0; r < numpages; r++)
					table[r] = (int *)malloc(required * sizeof(int));
					
				for(int j = 0; j < numpages; j++){
					for(int k = 0; k < required; k++){
						table[j][k] = -1;
					}
				}
				
				int page_faults = 0;
				
				printf("Page ref -> memory -> PF\n");
				
				for(i = 0; i < required; i++){
					page_faults++;
					append(&lfu, pages[i]);
					printf("%d -> ",pages[i]);
					printList(lfu);
					copyList(lfu, table, i, required);
					for(int j = (required-1)-i; j > 0; j--){
						printf(" - ");
					}
					printf(" -> %d\n",page_faults);
				}

				count = required;
				
				for(i = i; i < numpages; i++){
					printf("%d -> ",pages[i]);
					if(!checkList(lfu, pages[i])){
						int val = findLFU(lfu, pages, i, numpages);
						replaceFrame(&lfu, val, pages[i]);
						copyList(lfu, table, count++, required);
						printList(lfu);
						page_faults++;
						printf(" -> %d\n",page_faults);
					}
					else{
						printList(lfu);
						printf(" -> -\n");
					}					
				}
				printf("\n");
				printTable(table, count, required);
				printf("\n");
				printf("Total number of page faults : %d\n",page_faults);
				break;
			}
			case 6:{
				printf("Program terminated Successfully!\n");
				break;
			}
			default:printf("Invalid Input!\n");
		}
	}	
	return 0;
}
