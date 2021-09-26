#include<stdio.h>
float power(float x,int n)
{
float y=1;
if (n>0)
{
	
	for(int i=0;i<n;i++)
	{
		y=y*x;
	}
	return y;
}
else if(n==0)
{
	return 1;
}
else
{
	for(int i=0;i>n;i--)
	{
		y=y*x;
	}
	return 1/y;
}
}			
int main()
{
	int n;
	float x,result;
	printf("Enter the number and its power to be raised:");
	scanf("%f %d",&x,&n);
	result=power(x,n);
	printf("Answer is:%f\n",result);
	return 0;
}

