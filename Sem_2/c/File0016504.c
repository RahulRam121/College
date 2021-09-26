#include<stdio.h>
void main()
{	
	int n;
	int num[500],x,y=0;
	int con(int m);
        printf("Enter the number of terms:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		
		printf("Enter the %dth three digit number:",i+1);
		scanf("%d",&num[i]);
		
	}
	num[n]='\0';
	for (int j=0;j<n;j++)
	{
		int m=num[j];
		x=con(m);
		if (x==0)
		{
			y+=0;
		}
		else
		{
			y+=1;
			printf("well ordered no:%d\n",m);
		}
	}
	printf("Number of well ordered numbers are:%d\n",y);
}	
int con(int m)
{
int a=0,b=9,flag;
for (int i=0;i<3;i++)
{
a=m%10;
if (a<=b)
{
m=m/10;
flag=1;
b=a;
}
else
{
flag=0;
break;
}
}
return flag;
}

		

