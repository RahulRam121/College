#include<stdio.h>
void main()
{
int n,result;
long int ans;
long int fact(int n);
int rmnzt(long int ans);
printf("Enter the number:");
scanf("%d",&n);
ans=fact(n);
result=rmnzt(ans);
printf("The result:%d\n",result);
}
long int fact(int n)
{
if (n==0)
{
return 1;
}
else
{
return(n*fact(n-1));
}
}
int rmnzt(long int ans)
{
if (ans%10==0)
{
ans=ans/10;
rmnzt(ans);
}
else
{
return(ans%10);
}
}
