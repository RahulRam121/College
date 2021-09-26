#include<stdio.h>
int range(int);
void main()
{
int n;
printf("enter the limit of the range you want:");
scanf("%d",&n);
printf("the range is ");
range(n-1);
printf("\n");
}
int range(int i)
{
if(i>=0)
{
printf("%d",i);
return (0+range(i-1));
}
else
{
return 0;
}
}
