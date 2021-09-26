#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

void printMenu();
bool checkAvail(int arr1[], int arr2[], int n);
bool checkFinish(bool finish[], int n);

void printMenu(){
	printf("\n\t\tBanker's Algorithm\n1.Read Data\n2.Print Data\n3.Safety Sequence\n4.Exit\n\nEnter the option: ");
}

bool checkAvail(int arr1[], int arr2[], int n){

	for(int i = 0; i < n; i++){
		if(arr2[i] < arr1[i])
			return false;
	}
	return true;
}

bool checkFinish(bool finish[], int n){

	for(int i = 0; i < n; i++){
		if(!finish[i])
			return false;
	}
	return true;
}

int main(){
	
	int numProcesses;			//number of process
	int numResources;			//number of resources
	char process[MAX][3];		//name of the processes
	char resource[MAX];			//name of the resources
	int Avail[MAX];			//number of instances of each resoures
	int Max[MAX][MAX];			//max instances required
	int Alloc[MAX][MAX];		//allocated instances	
	int Need[MAX][MAX];			//need
	int choice = 1;
	
	while(choice != 4){
		printMenu();
		scanf("%d",&choice);
		switch(choice){
		
			case 1:{
				char str[50];
				char ch;
				char* token;
				int i;
				
				printf("Number of processes: ");
				scanf("%d",&numProcesses);				
				
				printf("Enter the name of the process: ");
				scanf("%c",&ch);
				scanf("%[^\n]%*c", str);
				
				token = strtok(str, " ");
				
				i = 0;
				while(token != NULL){
					strcpy(process[i++], token);
					token = strtok(NULL, " "); 
				}
				
				printf("Number of Resources: ");
				scanf("%d",&numResources);								
				
				printf("Enter the name of the resources: ");
				scanf("%c",&ch);
				scanf("%[^\n]%*c", str);
										
				token = strtok(str, " ");
				
				i = 0;
				while(token != NULL){
					resource[i++] = token[0];			
					token = strtok(NULL, " "); 
				}				
				
				for(i = 0; i < numResources; i++){
					printf("Number of Available instances of %c: ",resource[i]);
					scanf("%d",&Avail[i]);
				}		
				scanf("%c",&ch);								
				
				for(int j = 0; j < numProcesses; j++){
					i = 0;
					printf("Maximum Requirment of %s: ",process[j]);
					
					scanf("%[^\n]%*c", str);
					
					token = strtok(str, " ");
					
					while(token != NULL){
						Max[j][i++] = atoi(token);		
						token = strtok(NULL, " "); 
					}					
				}
				
				for(int j = 0; j < numProcesses; j++){
					i = 0;
					printf("Allocated instances to %s: ",process[j]);
					
					scanf("%[^\n]%*c", str);
					
					token = strtok(str, " ");
					
					while(token != NULL){
						Alloc[j][i++] = atoi(token);		
						token = strtok(NULL, " "); 
					}					
				}
				
				printf("Data is read from the user successfully!\n");				
				break;
			}
			
			case 2:{
				printf("Pid\t\tAlloc\t\tMax\t\tNeed\t\tAvail\n");
				printf("\t\t");
				for(int i = 0; i < 4; i++){
					for(int j = 0; j < numResources; j++){
						printf("%c ",resource[j]);
					}
					printf("\t\t");
				}
				printf("\n");
				for(int i = 0; i < numProcesses; i++){
					printf("%s\t\t",process[i]);
						for(int j = 0; j < numResources; j++){
							printf("%d ",Alloc[i][j]);
						}
						printf("\t\t");
						for(int j = 0; j < numResources; j++){
							printf("%d ",Max[i][j]);
						}
						printf("\t\t");
						for(int j = 0; j < numResources; j++){
							Need[i][j] = Max[i][j] - Alloc[i][j];
							printf("%d ",Need[i][j]);
						}
						printf("\t\t");
						if(i == 0){	
							for(int j = 0; j < numResources; j++){
								printf("%d ",Avail[j]);
							}
						}
						printf("\n");
				}
				break;
			}
			case 3:{
			
				char str[50];
				char ch;
				char* token;
				int k;
				int Request[numResources];
				int Work[numResources];
				bool Finish[numProcesses];
				char safetySeq[numProcesses][3];
				char tempProcess[10];
				int id = -1;
				int itr = 0;
				int prev = -1;
				bool safe = true;
				int count = 0;
				
				for(int i = 0; i < numProcesses; i++){
					Finish[i] = false;
				}
				
																											
				printf("Enter the process name(\"no\" to skip process request) : ");
				scanf("%s",tempProcess);
				if(strcmp(tempProcess,"no") != 0){
										
					for(int i = 0; i < numProcesses; i++){
						if(strcmp(tempProcess, process[i]) == 0){
							id = i;
							break;
						}
					}
					if(id == -1){
						printf("Invalid input!\n");
						break;
					}	
				
					scanf("%c",&ch);
					printf("Enter the Request : ");
					scanf("%[^\n]%*c", str);
						
					token = strtok(str, " ");
				
					k = 0;
					while(token != NULL){
						Request[k++] = atoi(token);		
						token = strtok(NULL, " "); 
					}		
				
					//Condition 1
					if(!checkAvail(Request, Need[id], numResources)){
						printf("Request is greater than the need! Request Rejected!\n");
						break;
					}
				
					//Condition 2
					if(!checkAvail(Request, Avail, numResources)){
						printf("Request is greater than Available! Process should wait!\n");
						break;
					}
					else{
						for(int i = 0; i < numResources; i++){
							Avail[i] -= Request[i];
							Alloc[id][i] += Request[i];
							Need[id][i] -= Request[i];
						}
					}
				
				}
				for(int i = 0; i < numResources; i++){
					Work[i] = Avail[i];
				}
										
				while(!checkFinish(Finish, numProcesses)){
				
					if(prev == itr){ 						
						safe = false;
						break;
					}			
					
					if(!Finish[itr] && checkAvail(Need[itr], Work, numResources)){
						strcpy(safetySeq[count++], process[itr]);
						prev = itr;
						Finish[itr] = true;
						for(int i = 0; i < numResources; i++){
							Work[i] += Alloc[itr][i];							
						}
					}
					
					if(prev == -1 && itr == numProcesses-1){
						safe = false;
						break;
					}
					
					itr++;
					itr = itr%numProcesses;
				}
				if(safe){
					printf("System is in safe state!\n");
					printf("Safety Sequence is : ");
					for(int i = 0; i < numProcesses; i++){
						printf("%s ",safetySeq[i]);
					}
					printf("\n");
				}	
				else
					printf("System is not in safe state!\n");
					
				if(strcmp(tempProcess,"no") != 0){
					for(int i = 0; i < numResources; i++){
						Avail[i] += Request[i];
						Alloc[id][i] -= Request[i];
						Need[id][i] += Request[i];
					}
				}
				break;
			}
			case 4:{
				printf("Program terminated Successfully!\n");
				exit(0);
			}
			default:printf("Invalid Input!\n");
		}
	}				
	
	return 0;
}
