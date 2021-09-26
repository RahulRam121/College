#include<stdio.h>
int main()
{	int n,s=0;
	printf("\nEnter number:");
	scanf("%d",&n);	
	do
	{	s+=n;
		printf("\nEnter number:");
		scanf("%d",&n);	
	}while(n!=-999);
	printf("Sum: %d",s);
	return 0;
}
