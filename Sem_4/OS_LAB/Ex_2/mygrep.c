#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<errno.h>

#define BUFFERSIZE 1024

int main(int argc,char **argv){
	int fd1;
	int fd2;
	char buf1[BUFFERSIZE];
	char buf2[BUFFERSIZE];
	char pattern[100];
	char *source = argv[1];
	char *patternfile = argv[2];
	
	if((fd1 = open(source,O_RDONLY)) == -1){
		printf("Error opening source file :%d\n",errno);
	}
	
	else{
		printf("Source file open code :%d\n",fd1);
				
		if((fd2 = open(patternfile,O_RDONLY))!= -1){
			printf("Pattern file open code :%d\n",fd2);
			
			read(fd1, buf2, BUFFERSIZE);
			strcpy(pattern,buf2);
			printf("pattern : %s",pattern);
		}
		else
			printf("Error opening destination file :%d",fd2);
	}
}
