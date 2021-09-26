#include<stdio.h>
void main()
{
	int num,flag;
	printf("Enter a number:");
	scanf("%d",&num);
	flag=(num%2==0)?0:1;
	printf("value of the flag is:");
	printf("%d",flag);
	printf("\n");
}
