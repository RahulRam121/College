#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <semaphore.h>
#include <pthread.h> // for semaphore operations sem_init,sem_wait,sem_post
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <sys/errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio_ext.h>
#include <ctype.h>
extern int errno;
#define SIZE 10 /* size of the shared buffer*/
#define VARSIZE 1 /* size of shared variable=1byte*/
#define INPUTSIZE 20
#define SHMPERM 0666 /* shared memory permissions */
int segid; /* id for shared memory bufer */
int empty_id;
int full_id;
int mutex_id;
char * buff;
char * input_string;
sem_t *empty;
sem_t *full;
sem_t *mutex;
int p=0,c=0;

int main(){
	int i=0;
	char *turn = (char *)malloc(sizeof(char)*5);	
	
	int id = shmget(111,50,0);
	segid = shmget (IPC_PRIVATE, SIZE, 0);
	empty_id = shmget(IPC_PRIVATE, sizeof(sem_t), 0);
	full_id = shmget(IPC_PRIVATE, sizeof(sem_t), 0);
	mutex_id = shmget(IPC_PRIVATE, sizeof(sem_t), 0);
	
	printf("here\n");
	
	buff = shmat( segid, (char *)0, 0 );
	empty = shmat(empty_id, (char *)0, 0);
	full = shmat(full_id, (char *)0, 0);
	mutex = shmat(mutex_id, (char *)0, 0);	
	turn = shmat(id,size(turn),0);	
	
	while(turn[0] == 's');	
	
	while (1){
		if(i>=strlen(buff)){
			printf("\n Consumer %d exited \n",getpid());
			exit(1);
		}
		printf("\nConsumer %d trying to aquire Semaphore Full \n",getpid());
		sem_wait(full);
		printf("\nConsumer %d successfully aquired Semaphore Full \n",getpid());
		printf("\nConsumer %d trying to aquire Semaphore Mutex \n",getpid());
		sem_wait(mutex);
		printf("\nConsumer %d successfully aquired Semaphore Mutex\n",getpid());
		printf("\nConsumer %d Consumed Item [ %c ] \n",getpid(),buff[c]);
		buff[c]=' ';
		c++;
		printf("\nItems in Buffer %d \n",strlen(buff));
		i++;
		sem_post(mutex);
		printf("\nConsumer %d released Semaphore Mutex \n",getpid());
		sem_post(empty);
		printf("\nConsumer %d released Semaphore Empty \n",getpid());
		sleep(1);
	} //while
	
	shmdt(buff);
	shmdt(empty);
	shmdt(full);

	return 0;
	
}
