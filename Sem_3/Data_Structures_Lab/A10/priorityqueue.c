#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"priorityqueue.h"

int main(){
	pq *h;
	det priorityelement;
	char sname[25];
	float sal;
	int maxemployees,id1,ch;
	printf("Enter the number of employees : ");
	scanf("%d",&maxemployees);
	h=createPQ(maxemployees);
	for(int i=0;i<maxemployees;i++){
		printf("\nEnter the %dth Employee details!\n",i+1);
		printf("Enter Name   : ");
		scanf("%s",sname);
		printf("Enter ID     : ");
		scanf("%d",&id1);		
		printf("Enter salary : ");
		scanf("%f",&sal);
		h=insert(sname,id1,sal,h);	
		display(h); 
	}
	printf("\nMenu\n1.Insert Employee Details.\n2.Dequeue Highest Salary Employee.\n3.Display Tree.\n4.Exit.\nEnter your choice : ");
	scanf("%d",&ch);
	while(ch!=4){
		switch(ch){
			case 1:{			
				printf("\nEnter Employee Details!\n");
				printf("Enter Name   : ");
				scanf("%s",sname);
				printf("Enter ID     : ");
				scanf("%d",&id1);		
				printf("Enter salary : ");
				scanf("%f",&sal);
				h=insert(sname,id1,sal,h);
				display(h);
				break;
			}
			case 2:{
				priorityelement=deletemax(h);
				display2(priorityelement);
				display(h);				
				break;
			}
			case 3:display(h);break;
			case 4:return 0;
			default:printf("Invalid Input!\n");									
		}
		printf("\nMenu\n1.Insert Employee Details.\n2.Dequeue Highest Salary Employee.\n3.Display Tree.\n4.Exit.\nEnter your choice : ");
		scanf("%d",&ch);
	}
	return 0;
}

