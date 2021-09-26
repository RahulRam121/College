//Egg timer
#include<stdio.h>
void main()
{
int i,j,n,flag=1;
while(flag)
	{
	printf("Enter the number between 3 and 10:\n");
	scanf("%d",&n);
	if(n>=3 && n<=10)
		{
		for(i=1;i<=n;i++)
			{
		    	for(j=1;j<=i;j++)
		    		{
				printf(" ");
				}
		    	for(j=i;j<=n;j++)
				{
				printf("*");
				if(j<n)
					{
					printf("_");
					}
				}      		
			printf("\n");
			}
		for(i=2;i<=n;i++)
			{
		       	for(j=1;j<=n-i+1;j++)
				{
				printf(" ");
				}
			for(j=1;j<=i;j++)
				{
				printf("*");
				if(j<i)
			   		{
					printf("-");
					}
		       		}
			printf("\n");
		    	}
		flag=0;
		}
	else
		{
		printf("Invalid input:\n");
		}
	}
}

/*
Output:
Enter the number between 3 and 10:
4
 *_*_*_*
  *_*_*
   *_*
    *
   *-*
  *-*-*
 *-*-*-*
*/
