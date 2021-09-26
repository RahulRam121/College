#include<stdio.h>
void main()
{
	int flag,n,num,i,odd=0,even=0;
	printf("Enter the number of terms:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the %dth number:",i+1);
		scanf("%d",&num);
		flag=A1(num);
		if(flag==1)
		{
			even=even+num;
		}
		else
		{
			odd=odd+num;
		}
	}
	printf("The sum of even number is :%d\n",even);
	printf("The sum of odd number is :%d\n",odd);
}
int A1(int num)
{
	if(num%2==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

