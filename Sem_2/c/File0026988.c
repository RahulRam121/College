#include<stdio.h>
void main()
{
int num,c=0;
printf("Enter a number: ");
scanf("%d",&num);
while(num>0)
{
	if(num%10==5)
	{
		c+=1;
	}
	else
	{
		c=0;
	}
	num/=10;
	if(c==3)
	{
		break;
	}
	
}
if (c==3)
{
	printf("Yes\n");
}
else
{
	printf("no\n");
}
}
	
