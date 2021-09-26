#include<stdio.h>
char strncat(char str1[],char str2[]);
void main()
{
char str1[40],str2[20];
printf("Enter the 1st string:");
scanf("%s",str1);
printf("Enter the string to be appended:");
scanf("%s",str2);
str1[40]=strncat(str1,str2);
printf("The required string is:%s",str1);
}

char strncat(char str1[],char str2[])
{
int count=0;
for (int i=0;str1[i]!=0;i++)
{
count+=1;
}
for (int i=0;str2[i]!=0;i++)
{
str1[i+count]=str2[i];
}
return str1;
}
