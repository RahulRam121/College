#include<stdio.h>
void main()
{
int n;
float ans;
float productrec(int n);
printf("Enter the number of terms:");
scanf("%d",&n);
ans=productrec(n);
printf("The answer is:%f\n",ans);
}
float productrec(int n)
{
float count;	
if(n==0)
{
	return 1;
}
else
{
	printf("enter the number:");
	scanf("%f",&count);
	return(count*productrec(n-1));
}
}
