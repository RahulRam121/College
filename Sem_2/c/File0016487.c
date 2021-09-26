#include<stdio.h>
#include<stdlib.h>
void readinput(int *a[20],int row,int col);
void computetable(int *a[20],int *b[20],int *c[20],int row,int col);
void display(int *a[20],int row,int col);
int main()
{
int row,col;
int *a[20], *b[20], *c[20];
printf("Enter the number of rows:");
scanf("%d",&row);
printf("Enter the number of coloumns:");
scanf("%d",&col);
for(int i=0;i<row;i++)
{
a[i]=(int *) malloc (col*sizeof(int));
b[i]=(int *) malloc (col*sizeof(int));
c[i]=(int *) malloc (col*sizeof(int));
}
printf("First table:\n");
readinput(a,row,col);
printf("Second table:\n");
readinput(b,row,col);
computetable(a,b,c,row,col);
display(c,row,col);
return 0;
}
void readinput(int *a[20],int x,int y)
{
for(int i=0;i<x;i++)
{
for(int j=0;j<y;j++)
{
printf("Enter the %dth row %dth column element:",i+1,j+1);
scanf("%d",(a[i]+j));
}
}
return;
}
void computetable(int *a[20],int *b[20],int *c[20],int x,int y)
{
	for(int i=0;i<x;i++)
	{
	for(int j=0;j<y;j++)
	{
	if (*(a[i]+j)>*(b[i]+j))
	{
		*(c[i]+j)=*(a[i]+j);
	}
	else
	{
	*(c[i]+j)=*(b[i]+j);	
	}
	}
	}
	return;
}
void display(int *a[20],int x,int y)
{
	printf("The resultant table is:\n");
	for(int i=0;i<x;i++)
	{
		for (int j=0;j<y;j++)
		{
			printf("%d\t",*(a[i]+j));    
		}
		printf("\n");
	}
	return;
}
