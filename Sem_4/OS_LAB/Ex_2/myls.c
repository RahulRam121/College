#include<stdio.h>
#include<dirent.h>

int main(){
	
	char pathname[20];
	printf("Enter the name of the directory (specify path name):");	
	scanf("%s",pathname);
	
	struct dirent *de;
	DIR *dr = opendir(pathname);
	
	if(dr == NULL){
		printf("Could not find/open the directory!\n");
		return 0;
	}
	while ((de = readdir(dr)) != NULL) 
        printf("%s\n", de->d_name);
            
    closedir(dr);
	return 0;
}

