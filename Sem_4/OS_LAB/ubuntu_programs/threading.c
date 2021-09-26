#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

/* this data will be shared by the thread(s) */
int average; 
int min = MAX;
int max = -1;
int size = 0;

/* threads call this functions */
void *findAverage(void *args); 
void *findMinimum(void *args);
void *findMaximum(void *args);

int main(int argc, char *argv[]){
	
	/* thread identifiers */
	pthread_t avrg_t; 	
	pthread_t min_t;
	pthread_t max_t;
	
	if (argc < 2){
		fprintf(stderr,"usage: a.out <integer value>\n");
		return -1;
	}
	
	int *nums = (int *)malloc(sizeof(int) * (argc - 1));
	
	for(int i =1; i < argc; i++){
		nums[i-1] = atoi(argv[i]);
		size++;
	}
	
	/* create the threads */
	pthread_create(&avrg_t,NULL,findAverage,(void*)nums);
	pthread_create(&min_t,NULL,findMinimum,(void*)nums);
	pthread_create(&max_t,NULL,findMaximum,(void*)nums);
	
	/* wait for the threads to exit */
	pthread_join(avrg_t,NULL);
	pthread_join(min_t,NULL);
	pthread_join(max_t,NULL);
	
	printf("The average value is %d\n",average);
	printf("The minimum value is %d\n",min);
	printf("The maximum value is %d\n",max);
}

/* The thread will begin control in below functions */
void *findAverage(void *param){
	int *num = (int *)param;
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += num[i];
	average = sum/(size);
	pthread_exit(0);
}

void *findMinimum(void *param){
	int *num = (int *)param;
	for(int i = 0; i < size; i++){
		if(min > num[i])
			min = num[i];
	}
	pthread_exit(0);
}

void *findMaximum(void *param){
	int *num = (int *)param;
	for(int i = 0; i < size; i++){
		if(max < num[i])
			max = num[i];
	}
	pthread_exit(0);
}
