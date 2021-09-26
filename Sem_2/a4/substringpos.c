#include<stdio.h>
#include<string.h>
void main()
{
char str[20],substr[10];
int c,len=0,slen=0,count,j,i;
printf("Enter a string:");
scanf("%s",str);
printf("Enter the substring:");
scanf("%s",substr);
for(int k=0;str[k]!=0;k++)
{
len+=1;
}
printf("%d",len);
for(int l=0;substr[l]!=0;l++)
{
slen+=1;
}
printf("%d",slen);
for(int i=len-1;i>slen-1;i--)
{
c=0;
for(j=i;j>=(i-len-1);j--)
{
if (str[j]==substr[slen-1-c])
{
c+=1;
if (c==slen-1)
{
break;
}
}
else
{
break;
}
}
if (c==slen-1)
{
break;
}
}
printf("pos is:%d",j);
}
    