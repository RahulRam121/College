#include<stdio.h>
char strncpy(char dest[],char src[],int n);
void main()
{
char src[20],dest[20];
int n;
printf("Enter the source string:");
scanf("%s",src);
printf("Enter the number of charcters to be copied:");
scanf("%d",&n);
dest[20]=strncpy(dest,src,n);
printf("The required string is:%s",dest);
}
char strncpy(char dest[],char src[],int n)
{
for (int i=0;i<n;i++)
{
dest[i]=src[i];
}
return dest;
}