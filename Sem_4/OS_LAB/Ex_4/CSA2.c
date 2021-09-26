#include<stdio.h>
#include<string.h>
#include<stdbool.h>

void printMenu();
void printReport1(int process,char ID[20][5],int a_time[],int b_time[],int t_time[],int w_time[]);
void printReport2(int process,char ID[20][5],int a_time[],int b_time[],int t_time[],int w_time[],int priority[]);
void printGanttChart(int chart[100], int t,char ID [][5]);
bool checkTB(int tb_time[], int n);

int main(){
	
	int choice1 = 0;
	int pchart[20];
	int chart[100];	
	int process;
	char ID[20][5];
	int a_time[20], b_time[20], priority[20];
	int t_time[20], w_time[20], tb_time[20];
	
	while(choice1 != 3){
		printMenu();
		scanf("%d",&choice1);
		for(int i=0 ; i<100 ; i++){
			chart[i] = 0;
		}
		switch(choice1){
			case 1:{				
				char choice2 = 'Y';
				while(choice2 == 'Y'){
					for(int i=0 ; i<100 ; i++){
						chart[i] = 0;
					}
					printf("\tROUND ROBIN CPU SCHEDULER\n");
					printf("Number of Processes: ");
					scanf("%d",&process);
					
					for(int i=0 ; i<process ; i++){
						printf("Process ID: ");
						scanf("%s",ID[i]);
						printf("Arrival Time: ");
						scanf("%d",&a_time[i]);
						printf("Burst Time: ");
						scanf("%d",&b_time[i]);
						tb_time[i] = b_time[i];
						pchart[i] = i+1;
					}
					
					int wtime = 0;
					while(checkTB(tb_time,process)){
						for(int i=0 ; i<process ; i++){
							for(int j=0 ; j<process ; j++){
								if(a_time[j] == i){
									for(int k=0 ; k<2 ; k++){
										if(tb_time[j] != 0){
											if(wtime!=0){
												if(chart[wtime-1] != pchart[j] || k==0){
													chart[wtime] = pchart[j];
												}	
											} 
											else{
												chart[wtime] = pchart[j];
											}											
											tb_time[j]--;
											wtime++;
											if(tb_time[j]==0){
												t_time[j] = wtime - a_time[j];
											}
										}
										else
											break;
									}																							
								}
							}					
						}	
					}
					for(int i=0 ; i<process ; i++){
						w_time[i] = t_time[i] - b_time[i];
					}
					
					printReport1(process,ID,a_time,b_time,t_time,w_time);
					printGanttChart(chart,wtime,ID);
					printf("Want to Contiue(Y/N): ");
					scanf(" %c",&choice2);
				}				
				break;
			}
			case 2:{				
				char choice3;
				char choice2 = 'Y';
				while(choice2 == 'Y'){
					printf("\tPRIORITY CPU SCHEDULER\n");
					printf("a.Non preemptive PRIORITY\nb.Pre emptive PRIORITY\nEnter your option: ");
					scanf(" %c",&choice3);
					switch(choice3){
						case 'a':{
							printf("Number of Processes: ");
							scanf("%d",&process);
							for(int i=0 ; i<process ; i++){
								printf("Process ID: ");
								scanf("%s",ID[i]);
								printf("Arrival Time: ");
								scanf("%d",&a_time[i]);
								printf("Burst Time: ");
								scanf("%d",&b_time[i]);
								printf("Priority: ");
								scanf("%d",&priority[i]);
								pchart[i] = i+1;
							}
							int check[20], wtime=0;
							for(int i=0 ; i<process ; i++){
								check[i] = 0;
							}
							int lpi, mp;
							for(int i=0 ; i<process ; i++){							//arrival time
								mp = 10000;
								for(int j=0 ; j<process ; j++){						//process
									if(a_time[j] <= i){
										for(int k=0 ; k<process ; k++){			 	//priority
											if(priority[j] == k+1 && check[j] != 1 && k<mp){
												lpi = j;
												mp = k;
												break;
												//lb = b_time[j];
											}
										}										
									}
								}
								chart[wtime] = pchart[lpi];
								t_time[lpi] = (wtime + b_time[lpi]) - a_time[lpi];
								wtime += b_time[lpi];
								i += b_time[lpi] - 1;
								check[lpi] = 1;														
							}
							
							for(int i=0 ; i<process ; i++){
								mp = 10000;
								for(int j=0 ; j<process ; j++){		
									for(int k=0; k<process ; k++)	{
										if(priority[j] == k+1 && check[j] != 1 && k<mp){
											lpi = j;
											mp =k;
											break;
											//lb = b_time[j];
										}
									}
									
								}
								if(mp != 10000){
									chart[wtime] = pchart[lpi];
									t_time[lpi] = (wtime - a_time[lpi]) + b_time[lpi];
									wtime += b_time[lpi];
									check[lpi] = 1;
								}
							}
							for(int i=0 ; i<process ; i++){
								w_time[i] = t_time[i] - b_time[i];
							}
							printReport2(process,ID,a_time,b_time,t_time,w_time,priority);
							printGanttChart(chart,wtime,ID);
							break;
						}												
						case 'b':{
							printf("Number of Processes: ");
							scanf("%d",&process);
							for(int i=0 ; i<process ; i++){
								printf("Process ID: ");
								scanf("%s",ID[i]);
								printf("Arrival Time: ");
								scanf("%d",&a_time[i]);
								printf("Burst Time: ");
								scanf("%d",&b_time[i]);
								printf("Priority: ");
								scanf("%d",&priority[i]);								
								pchart[i] = i+1;
							}
							int wtime = 0, tb_time[20];
							for(int i=0 ; i<process ; i++){
								tb_time[i] = b_time[i];
								t_time[i] = 0;
							}
							int prev = 10000, lpi, mp = 10000;
							for(int i=0 ; i<process ; i++){
								mp = 10000;
								for(int j=0 ; j<process ; j++){								
									if(a_time[j] <= i){
										for(int k=0 ; k<process ; k++){
											if(tb_time[j] != 0 && priority[j] == k+1 && k<mp){
												lpi = j;
												mp = k;
												break;												
											}
										}
									}
								}	
								if(prev != lpi){
									chart[wtime] = pchart[lpi];								
								}
								wtime++;
								prev = lpi;							
								tb_time[lpi]--;
								if(tb_time[lpi] == 0){
									t_time[lpi] = wtime;
								}
							}
							for(int i=0 ; i<process ; i++){
								mp = 10000;
								for(int j=0 ; j<process ; j++){
									for(int k=0; k<process ; k++)	{
										if(priority[j] == k+1 && tb_time[j] != 0 && k<mp){
											lpi = j;
											mp =k;
											break;
										}
									}
								}														
								if(prev != lpi){
									chart[wtime] = pchart[lpi];
								}
								wtime += tb_time[lpi];	
								tb_time[lpi] = 0;
								t_time[lpi] = wtime - a_time[lpi];;
							}
							for(int i=0 ; i<process ; i++){
								w_time[i] = t_time[i] - b_time[i];
							}
			
							printReport2(process,ID,a_time,b_time,t_time,w_time,priority);
							printGanttChart(chart,wtime,ID);
							break;
						}
						default:printf("Invalid Input!\n");
					}
					printf("Want to Contiue(Y/N): ");
					scanf(" %c",&choice2);
				}				
				break;
			}
			case 3:{
				printf("Program Terminated!\n");
				break;
			}
			default:printf("Invalid input!\n");
		}
	}	
	return 0;
}

void printMenu(){
	printf("\t\tCPU SCHEDULING ALGORITHMS\n");
	printf("1.ROUND ROBIN\n2.PRIORITY\n3.EXIT\nEnter your option: ");
}

void printReport1(int process,char ID[20][5],int a_time[],int b_time[],int t_time[],int w_time[]){

	float a_ttime = 0.0, a_wtime = 0.0;

	printf("Process_ID\tArrival_Time\tBurst_Time\tTurnaround_Time\tWaiting_Time\n");
	printf("-----------------------------------------------------------------------------\n");
	for(int i=0 ; i<process ; i++){
		printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\n",ID[i],a_time[i],b_time[i],t_time[i],w_time[i]);
		a_ttime += (float)t_time[i];
		
		a_wtime += (float)w_time[i];
	}
	printf("-----------------------------------------------------------------------------\n");
	printf("\t\t\t\tAverage\t\t%.1f\t\t%.1f\n",a_ttime/process,a_wtime/process);
	printf("\t\t\t\t---------------------------------------------\n");
}

void printReport2(int process,char ID[20][5],int a_time[],int b_time[],int t_time[],int w_time[],int priority[]){

	float a_ttime = 0.0, a_wtime = 0.0;

	printf("Process_ID\tArrival_Time\tBurst_Time\tPriority\tTurnaround_Time\tWaiting_Time\n");
	printf("---------------------------------------------------------------------------------------------\n");
	for(int i=0 ; i<process ; i++){
		printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",ID[i],a_time[i],b_time[i],priority[i],t_time[i],w_time[i]);
		a_ttime += (float)t_time[i];
		a_wtime += (float)w_time[i];
	}
	printf("---------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\t\tAverage\t\t%.1f\t\t%.1f\n",a_ttime/process,a_wtime/process);
	printf("\t\t\t\t\t\t---------------------------------------------\n");
}

void printGanttChart(int chart[100], int t,char ID[][5]){
	int count = 0;
	printf("Gantt Chart:\n");
	printf("Each '--' represents a single time slice.\n");
	for(int i=0 ; i<t ; i++){
		if(chart[i] != 0){
			count++;
		}
	}
	for(int i=0 ; i<t*2+count+1 ; i++){
		printf("-");
	}
	printf("\n");
	for(int i=0 ; i<t ; i++){
		if(chart[i]!=0){
			printf("|%s",ID[chart[i]-1]);
		}
		else{
			printf("  ");
		}
	}
	printf("|\n");
	for(int i=0 ; i<t*2+count+1 ; i++){
		printf("-");
	}
	printf("\n");
	//temp = -1;
	for(int i=0 ; i<t ; i++){
		if(chart[i]!=0){
			//temp = chart[i];
			if(i>9){
				printf("%d ",i);
			}
			else{
				printf("%d  ",i);	
			}			
		}
		else{
			printf("  ");
		}
	}
	printf("%d\n",t);
}

bool checkTB(int tb_time[], int n){
	int sum = 0;
	for(int i=0 ; i<n ; i++){
		sum += tb_time[i];
	}
	if(sum != 0)
		return true;
	else
		return false;
}
