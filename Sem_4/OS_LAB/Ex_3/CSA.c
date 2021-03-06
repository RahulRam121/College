#include<stdio.h>
#include<string.h>

void printMenu();
void printReport(int process,char ID[20][5],int a_time[],int b_time[],int t_time[],int w_time[]);
void printGanttChart(int chart[100], int t,char ID [][5]);

int main(){
	
	int choice1 = 0;
	int pchart[20];
	int chart[100];	
	int process;
	char ID[20][5];
	int a_time[20], b_time[20];
	int t_time[20], w_time[20];
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
					printf("\tFCFS CPU SCHEDULER\n");
					printf("Number of Processes: ");
					scanf("%d",&process);
					for(int i=0 ; i<process ; i++){
						printf("Process ID: ");
						scanf("%s",ID[i]);
						printf("Arrival Time: ");
						scanf("%d",&a_time[i]);
						printf("Burst Time: ");
						scanf("%d",&b_time[i]);
						pchart[i] = i+1;
					}
					int wtime = 0;
					for(int i=0 ; i<process ; i++){
						for(int j=0 ; j<process ; j++){
							if(a_time[j] == i){
								chart[wtime] = pchart[j];
								w_time[j] = wtime - a_time[j];
								t_time[j] = w_time[j] + b_time[j];
								wtime += b_time[j];						
							}
						}					
					}
					printReport(process,ID,a_time,b_time,t_time,w_time);
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
					printf("\tSJF CPU SCHEDULER\n");
					printf("a.Non preemptive SJF\nb.Pre emptive SJF\nEnter your option: ");
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
								pchart[i] = i+1;
							}
							int check[20], wtime=0;
							for(int i=0 ; i<process ; i++){
								check[i] = 0;
							}
							for(int i=0 ; i<process ; i++){
								int lbi, lb = 10000;
								for(int j=0 ; j<process ; j++){								
									if(a_time[j] <= i){
										if(b_time[j] < lb && check[j] != 1){
											lbi = j;
											lb = b_time[j];
										}
									}
								}
								chart[wtime] = pchart[lbi];
								w_time[lbi] = wtime - a_time[lbi];
								t_time[lbi] = w_time[lbi] + b_time[lbi];
								wtime += b_time[lbi];
								i += b_time[lbi] - 1;
								check[lbi] = 1;
														
							}
							for(int i=0 ; i<process ; i++){
								int lbi, lb = 10000;
								for(int j=0 ; j<process ; j++){		
															
									if(b_time[j] < lb && check[j] != 1){
										lbi = j;
										lb = b_time[j];
									}
								}
								if(lb != 10000){
									chart[wtime] = pchart[lbi];
									w_time[lbi] = wtime - a_time[lbi];
									t_time[lbi] = w_time[lbi] + b_time[lbi];
									wtime += b_time[lbi];
									check[lbi] = 1;
								}
							}
							printReport(process,ID,a_time,b_time,t_time,w_time);
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
								pchart[i] = i+1;
							}
							int wtime = 0, tb_time[20];
							for(int i=0 ; i<process ; i++){
								tb_time[i] = b_time[i];
								t_time[i] = 0;
							}
							int prev = 10000;
							for(int i=0 ; i<process ; i++){
								int lbi, lb = 10000;
								for(int j=0 ; j<process ; j++){								
									if(a_time[j] <= i){
										if(tb_time[j] < lb && tb_time[j] > 0){
											lb = tb_time[j];
											lbi = j;
										}
									}
								}	
								if(prev != lbi){
									chart[wtime] = pchart[lbi];
									w_time[lbi] = wtime - a_time[lbi];								
								}
								wtime++;
								prev = lbi;							
								tb_time[lbi]--;
							}
							for(int i=0 ; i<process ; i++){
								int lbi, lb = 10000;
								for(int j=0 ; j<process ; j++){
									if(tb_time[j] < lb && tb_time[j] > 0){
										lb = tb_time[j];
										lbi = j;
									}
								}														
								if(prev != lbi){
									chart[wtime] = pchart[lbi];
									w_time[lbi] = ((wtime) -(b_time[lbi] - tb_time[lbi]) ) - a_time[lbi];
								}
								wtime += tb_time[lbi];	
								tb_time[lbi] = 0;
								t_time[lbi] = w_time[lbi] + b_time[lbi];
							}
							for(int i=0 ; i<process ; i++){
									if(t_time[i] == 0){
										t_time[i] = w_time[i] + b_time[i];
									}
							}
			
							printReport(process,ID,a_time,b_time,t_time,w_time);
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
	printf("1.FCFS\n2.SJF\n3.EXIT\nEnter your option: ");
}

void printReport(int process,char ID[20][5],int a_time[],int b_time[],int t_time[],int w_time[]){

	float a_ttime = 0.0, a_wtime = 0.0;

	printf("Process_ID\tArrival_Time\tBurst_Time\tTurnaround_Time\tWaiting Time\n");
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
	int temp = -1;
	for(int i=0 ; i<t ; i++){
		if(chart[i] != temp && chart[i]!=0){
			temp = chart[i];
			printf("|%s",ID[chart[i]-1]);
		}
		else{
			printf("  ");
		}
	}
	temp = -1;
	printf("|\n");
	for(int i=0 ; i<t*2+count+1 ; i++){
		printf("-");
	}
	printf("\n");
	for(int i=0 ; i<t ; i++){
		if(chart[i] != temp && chart[i]!=0){
			temp = chart[i];
			if(i < 10){
				printf("%d  ",i);
			}
			else
				printf("%d ",i);			
		}
		else{
			printf("  ");
		}
	}
	printf("%d\n",t);
}
