#include<stdio.h>
void main()
{
	int num,count,i,sum=0;
	printf("Enter a number:");
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		printf("Enter the %dth number",i+1);
		scanf("%d",&count);
		sum=sum+count;
	}
	printf("The sum of %d number is %d:\n",num,sum);
}
