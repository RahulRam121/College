#include<stdio.h>
void main()
{
int str1[20],str2[10];
int n;
printf("Enter number of terms in array:");
scanf("%d",&n);
for (int i=0;i<n;i++)
{
printf("Enter the %d th term:",i+1);
scanf("%d",&str1[i]);
}
str1[n]='\0';

for (int i=0;i<10;i++)
{
str2[i]=0;
}
str2[10]='\0';

for(int i=0;i<n;i++)
{
if(str1[i]==0)
{
	str2[0]+=1;
}
else if(str1[i]==1)
{
str2[1]+=1;
}
else if(str1[i]==2)
{
str2[2]+=1;
}
else if(str1[i]==3)
{
str2[3]+=1;
}
else if(str1[i]==4)
{
str2[4]+=1;
}
else if(str1[i]==5)
{
str2[5]+=1;
}
else if(str1[6]==1)
{
str2[6]+=1;
}
else if(str1[i]==6)
{
str2[7]+=1;
}
else if(str1[i]==8)
{
str2[8]+=1;
}
else if(str1[i]==9)
{
str2[9]+=1;
}
}

int a=0;
for (int i=0;i<n;i++)
{
	if (str2[i]>a)
	{
		a=str2[i];
	}
	else
	{
		a=a;
	}
}
for (int i=a;i>0;i--)
{
	for(int j=0;j<10;j++)
	{
		if(str2[j]>=i)
		{
			printf("*");
		}
		else
		{
		printf(" ");
		}
	}
	printf("\n");
}
for (int i=0;i<10;i++)
{
	printf("%d",i);
}
printf("\n");
}


