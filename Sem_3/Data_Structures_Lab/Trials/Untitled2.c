#includede<stdio.h>
#include<stdlib.h>

typedef struct mynode
{
	char data;
	struct mynode *next;
}node;

int main()
{
	char exp[20];
	int n,w;
	printf("ENter n:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	
	scanf("%c",&exp[i]);
	}
	w=isbalanced(exp,n);
	return o;
}

int isbalanced(char exp[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(exp[i]=='{' ||exp[i]=='(' || exp[i]=='[')
		{
			push(exp[i]);
		}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	}
}
