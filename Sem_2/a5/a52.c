#include<stdio.h>
#include<string.h>
int countword(char *ptr);
int main()
{
char str[100],str1[20][50];
char *ptr[20];
int c=0,c1,c2=0,x,c3=0,ct,count=0;
printf("Enter the line of text and type END at the end of each line:");
scanf("%[^\n]%*c",str);
x=strlen(str);
printf("%d",x); 
for(int i=0;i<x-2;i++)
{
	c1=0;
	if(str[i]=='E' && str[i+1]=='N'  && str[i+2]=='D' && str[i+3]=='\0')
	{
	for(int j=c;j<i-1;j++)
	{
		str1[c3][c1]=str[j];
		c1+=1;
	}
	ptr[c2]=&str1[c3][0];
	c2+=1;
	c3+=1;
	c=i+3;
	}	
	else if(str[i]=='E' && str[i+1]=='N'  && str[i+2]=='D' && str[i+3]==' ')
	{
	for(int l=c;l<i-1;l++)
	{
		str1[c3][c1]=str[l];
		c1+=1;
	}
	ptr[c2]=&str1[c3][0];
	c2+=1;
	c3+=1;
	c=i+4;
	}
	
}
for (int i=0;i<c2;i++)
{
ct=countword(ptr[i]);
count=count+ct;
}
printf("Number of words in the given lines of text is:%d",count);
return 0;
}
int countword(char *ptr)
{
	int ct=0;
	for (int j=0;*(ptr+j)!='\0';j++)
	{
		if(*(ptr+j)==' ')
		{
			ct+=1;
		}
	}
	return ct+1;
}


	
	
	
	
    