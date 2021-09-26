#include <stdio.h>


int main(){
	int choice1 = 1;
	
	
	while(choice1 != 3){
		printf("File Organization Techniques\n");
		printf("1.Single Level Directory\n2.Tree structures Directory\nEnter your option: ");
		scanf("%d",&choice1);
		switch(choice1){
			case 1:{
			
				int choice2 = 1;
				char filenames[10][10];
				int location[10];
				int count = 0;
				
				while(choice2 != 3){
					printf("1.Create a file\n2.List the files\nEnter your option: ");
					scanf("%d",&choice2);
					
					switch(choice2){
						case 1:{
							char filename[10];
							printf("Enter the name of the file: ");
							scanf("%s",filename);
							
							for(int i = 0; i < count; i++){
								if(strcmp(filename, filenames[i]) == 0){
									printf("File already exists!\n");
									break;
								}
							}
							FILE *fptr = fopen(filename, "w");
							fclose(fptr);
							strcpy(filenames[count], fiename);
							
							break;
						}
						case 2:{
						
							break;
						}
						case 3:{
						
							break;
						}
						default:printf("Invalid Input!\n");
					}
					
				}
				break;
			}
			case 2:{
			
				break;
			}			
			case 3:{
				
				break;
			}
			default:printf("Invalid Input!\n");		
		}
	}
	
	return 0;
}
