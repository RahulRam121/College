#include<stdio.h>
void pushZeroToEnd(int arr[],int n);
void main()
{
int n,arr[100];
printf("Enter the number of terms:");
scanf("%d",&n);
for (int i=0;i<n;i++)
{
	printf("Enter the %d th number:",i+1);
	scanf("%d",&arr[i]);
}
arr[n]='\0';
printf("Elements of the old array:\n");
for (int i=0;i<n;i++)
{
printf("%dth element is:%d\n",i+1,arr[i]);
}
pushZeroToEnd(arr,n);
}
void pushZeroToEnd(int arr[],int n)
{
for (int i=0;i<n;i++)
{
for (int j=0;j<n;j++)
{
if(arr[j+1]!='\0')
{
if(arr[j]==0)
{
arr[j]=arr[j+1];
arr[j+1]=0;
j+=1;
}		
else
{
arr[j]=arr[j];
}
}
}
}
printf("Elements of the new array:\n");
for(int i=0;i<n;i++)
{
printf("%dth element is:%d\n",i+1,arr[i]);
}
}

