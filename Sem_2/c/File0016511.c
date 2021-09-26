#include<stdio.h>
int strch(char str[],char ch);
void main()
{
char str[20],ch;
int pos;
printf("Enter the string:");
scanf("%s",str);
printf("Enter the character whose position is to be found:");
scanf(" %c",&ch);
pos=strch(str,ch);
if (pos!=-1)
{
printf("The position of the character in the given string is:%d",pos);	
}
else
{
printf("The given character is not found");
}
}
int strch(char str[],char ch)
{
int count=0;
for (int i=0;str[i]!='\0';i++)
{
if (str[i]==ch)
{
count=i;
break;
}
else
{
count=-1;
}
}
return count; 
}
    

