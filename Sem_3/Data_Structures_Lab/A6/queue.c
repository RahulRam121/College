#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
#include"queue.h"
void enqueue(queue **Qf,queue **Qr,char jno[],float bt);
void display(queue **Qf,float awt);



int main()
{
	char j_no[4];
	int ch=1,temp1,temp2,a1=0,a2=0;
	float wt1=0,wt2=0,but,awt1,awt2;
	queue *Qf1=NULL,*Qf2=NULL,*Qr1=NULL,*Qr2=NULL;
	while(ch==1)
	{
		printf("Enter the Name of the job :");
		scanf("%s",j_no);
		printf("Enter its burst time:");
		scanf("%f",&but);
		temp1=wt1+but;
		temp2=wt2+but;
		if(temp1<temp2)
		{
			wt1=temp1;
			a1++;
			enqueue(&Qf1,&Qr1,j_no,but);
		}
		else if(temp1>temp2)
		{
			wt2=temp2;
			a2++;
			enqueue(&Qf2,&Qr2,j_no,but);
		}
		else
		{
			wt1=temp1;
			a1++;
			enqueue(&Qf1,&Qr1,j_no,but);
		}
		printf("Continue(1.Yes,2.No):");
		scanf("%d",&ch);
	}
	awt1=wt1/a1;
	awt2=wt2/a2;
	printf("\n");
	printf("Displaying Queue 1!\n");
	display(&Qf1,awt1);
	printf("Displaying Queue 2!\n");
	display(&Qf2,awt2);
	return 0;
}


