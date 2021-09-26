#include<stdio.h>
#include<string.h>
int main()
{
char str[20],repstr;
printf("Enter a string:");
scanf("%s",str);
int count=0,mid;
for (int i=0;str[i]!=0;i++)
{
count+=1;
}
mid=count/2;
for (int i=0;i<mid;i++)
{
repstr=str[count-1-i];
str[count-1-i]=str[i];
str[i]=repstr;
}
printf("The reqiured string:%s",str);
return 0;
}