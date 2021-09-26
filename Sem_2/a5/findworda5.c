#include <stdio.h>
#include<string.h>
int search(char *str,char *str1);
int main()
{ 
char str[100],str1[40]; 
int count; 
printf("Enter the string:"); 
scanf("%[^\n]%*c",str); 
printf("Enter the string to be found:");
scanf("%s",str1); 
count=search(&str,&str1); 
if (count!=0)
{
printf("Number of times the word repeated is:%d\n",count); 
}
else
{
	printf("Word not found\n");
}
return 0; 
} 
int search(char *str,char *str1) 
{
	int count=0,z=0,x; 
	x=strlen(str1);
	str1[x]=' ';
	int m=strlen(str),n=strlen(str1);	 
	for (int i=0;i<m-n+1;i++) 
	{ 
	count=0; 
	for(int j=0;j<n;j++) 
	{
		if (*(str+i+j)==*(str1+j)) 
		{
						
			count+=1; 
			if(count==n) 
			{ 
				z+=1; 
				
			} 
		} 
		else
		{
			break;
		}
	}
	while(str[i]!=' ')
	{
		i++;
	}
	
	} 
	return z; 
}
