#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

bool checkRepetition(int arr[], int size, int value){

	for(int i = 0; i < size; i++){
		if(arr[i] == value)
			return true;
	}
	return false;
}

void printFreeFrames(int arr[], int size){
	printf("Free Frames : ");
	for(int i = 0; i < size; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int* getFreeFrames(int *arr, int size, int frames){
	srand(time(0));
	int i = 0;
	int temp;
	while(i != size){
		temp = (rand() % frames) + 1;
		if(!checkRepetition(arr, i, temp)){
			arr[i] = temp;
			i++;
		}
	}
	return arr;
}


int main(){
	int memSize;
	int pageSize;
	char ms[3];
	int frames;
	int choice = 1;
	
	printf("Paging Technique :\n");
	printf("Enter the physical memory size: ");
	scanf("%d %s",&memSize, ms);

	printf("Enter the page size: ");
	scanf("%d %s",&pageSize, ms);
	
	frames = memSize/pageSize;
		
	printf("Physical memory is divided into %d frames.\n",frames);
	printf("After Initialization\n");
	
	srand(time(0));
	int length = (rand() % ((int)(frames*0.2) - (int)(frames*0.4) + 1)) + (int)(frames*0.2);
	int tlength = length;
	int randNum[length];
	int *freeFrames = getFreeFrames(randNum, length, frames);
	
	printFreeFrames(freeFrames, length);
	
	int lengths[20];
	for(int i = 0; i < 20; i++){
		lengths[i] = 0;
	}
	int pages[20][10];
	char IDs[20][3];
	int count = 0;
	
	while(choice != 5){
		printf("\n1.Process request\n2.Deallocation\n3.Page Table display for all input process.\n4.Free Frame List display\n5.Exit\nEnter Choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:{
				int size;
				char id[3];
				printf("Enter the Process requirement(ID ,size): ");
				scanf("%s ,%d",id, &size);

				int no_pages = size/pageSize;
				printf("Process is divided into %d pages\n",no_pages);
				if(no_pages > tlength){
					printf("Insufficient frames!\n");
					break;
				}
				strcpy(IDs[count],id);
				lengths[count] = no_pages;
				printf("\nPage Table for %s\n",id);
				for(int i = 0; i < no_pages; i++){
					printf("Page %d : Frame %d\n",i, freeFrames[i]);
					pages[count][i] = freeFrames[i];
				}
				printf("\n");
				count++;
				
				for(int i = 0; (i+no_pages) < length; i++){
					freeFrames[i] = freeFrames[i+no_pages];
				}
				tlength -= no_pages;
				
				
				break;
			}
			case 2:{
				char id[3];
				int index;
				printf("Enter the process id to be deallocated: ");
				scanf("%s",id);
				for(index = 0; index < count; index++){
					if(strcmp(IDs[index],id) == 0)
						break;
				}
				if(index == count){
					printf("Process id not found!\n");
					break;
				}
				
				for(int i = 0; i < lengths[index]; i++){
					freeFrames[i+tlength] = pages[index][i];
				}
				tlength += lengths[index];
				for(int i = index; (i+1) < length; i++){
					strcpy(IDs[i], IDs[i+1]);
					for(int j = 0; j < lengths[i+1]; j++){
						pages[i][j] = pages[i+1][j];
					}
					lengths[i] = lengths[i+1];
				}
				count--;
				printf("%s deallocated successfully!\n",id);
				break;
			}
			case 3:{
				for(int i = 0; i < count; i++){
					printf("Page Table for %s:\n",IDs[i]);
					for(int j = 0; j < lengths[i]; j++){
						printf("Page %d : Frame %d\n",j, pages[i][j]);
					}
					printf("\n");
				}
				break;
			}
			case 4:{
				printFreeFrames(freeFrames, tlength);
				break;
			}
			case 5:{
				printf("Program terminated successfully!\n");
				break;
			}
			default:printf("Invalid Input!\n");
		}
	}
	
	return 0;
}
