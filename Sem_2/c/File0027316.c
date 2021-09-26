#include<stdio.h>
int main()
{
int N,n,s=0,i;
printf("Enter the number of integers: ");
scanf("%d",&N);
for (i=0;i<N;i++)
{
	printf("Enter a integer:\n");
	scanf("%d",&n);
	if (n>0&&n<100)
		s+=n;
	else
		break;
}
if (n>0&&n<100)
	printf("the sum is %d\n",s);
else
	printf("Invalid input\n");
}
