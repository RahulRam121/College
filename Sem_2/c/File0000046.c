#include<stdio.h>

void reversenum(int *num);
int main()
{
	int num;
	printf("Enter a number:");
	scanf("%d",&num);
	reversenum(&num);
	return 0;
}

void reversenum(int *num)
{
int ans=0;
	while(*num>0)
	{
		ans*=10;
		ans=ans+*num%10;
		*num=*num/10;
	}
	printf("The answer is:%d\n",ans);
}	
