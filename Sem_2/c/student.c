#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Unit_Template structure
struct Unit_Template{
	char Subject_ID[10];
	char Subject_name[15];
	float marks;
};

//Student structure
struct Student{
	char name[15];
	int roll;
	struct Unit_Template unit;
};

//display() function to display the values of the array of structures
//accepts array of structures as parameters
void display(struct Student record[]){
	printf("\nDisplaying Student Details");
	for(int i = 0; i<5 ; i++){		
		printf("\nStudent %d Details:\n",i+1);
		printf("Student's Name : %s\n",record[i].name);
		printf("Roll Number    : %d\n",record[i].roll);
		printf("Subject ID     : %s\n",record[i].unit.Subject_ID);
		printf("Subject Name   : %s\n",record[i].unit.Subject_name);		
		printf("Marks          : %.2f\n",record[i].unit.marks);
	}
}

int main(){
	//creating array of Student structures
	struct Student record[5];
	for(int i = 0; i<5 ; i++){
		//reading input from the user
		printf("Enter Student %d Details:\n",i+1);
		printf("Student's Name : ");
		scanf(" %[^\n]%*c",record[i].name);
		printf("Roll Number    : ");
		scanf("%d",&record[i].roll);
		printf("Subject ID     : ");
		scanf("%s",record[i].unit.Subject_ID);
		printf("Subject Name   : ");
		scanf(" %[^\n]%*c",record[i].unit.Subject_name);
		printf("Marks          : ");
		scanf("%f",&record[i].unit.marks);	
	}
	//calling display() function
	display(record);
	return 0;
}
