#include<stdio.h>
int main()
{	int n,s=0;
	char ch='s';
	while(ch!='n')
	{	printf("\nEnter number:");
		scanf("%d",&n);	
		s+=n;
		printf("\nEnter ch:");
		scanf(" %c",&ch);
	}
	printf("Sum: %d",s);
	return 0;
}
