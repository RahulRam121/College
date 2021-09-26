#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<errno.h>

#define BUFFERSIZE 1024

int main(int argc,char **argv){
	
	int n_chars;
	char buf[BUFFERSIZE];
	char source[20];
	char destination[20];
	int fd1, fd2;
	
	if(argc > 4 || argc <3){
		printf("Invalid number of arguments!\n");
	}	
	if(argc == 3){
		strcpy(source,argv[1]);
		strcpy(destination,argv[2]);
	}
	else{
		if(strcmp(argv[1],"-i") != 0){
			printf("Invalid option!\n");
			exit(0);
		}
		else{
			strcpy(source,argv[2]);
			strcpy(destination,argv[3]);	
		}		
	}	
		
	fd1 = open(source,O_RDONLY);
	
	if(fd1 == -1)
		printf("Error opening source file :%d\n",errno);
	else{
		//printf("Source file open code :%d\n",fd1);
		fd2 = open(destination,O_RDWR | O_CREAT);
		if( fd2 != -1){
			//printf("Write file open code :%d\n",fd2);
			printf("mycp : overwrite '%s'?",destination);
			char choice;
			scanf(" %c",&choice);
			if(choice == 'y'){
				while( (n_chars = read(fd1, buf, BUFFERSIZE)) > 0 )
  				{
				    if( write(fd2, buf, n_chars) != n_chars )
				    	printf("Write error to %s\n", destination);
				    if( n_chars == -1 )
				        printf("Read error from %s\n", source);
				}
			}			
		}
		else
			printf("Error opening destination file :%d",fd2);
	}
	close(fd1);
	close(fd2);
}

