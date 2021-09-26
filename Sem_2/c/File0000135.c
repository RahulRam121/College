#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	char name[20],address[20];
	int a;
	
}example;
void main()
{
	example ex;
	int n=5,a1;
	FILE *fp=fopen("xample.dat","wb");
	printf("1 or2:");
	scanf("%d",&a1);
	if (a1==1)
	{
	
	for (int i=0;i<n;i++)
	{
		scanf("%s",ex.name);
		scanf("%s",ex.address);
		scanf("%d",ex.a);
		fwrite(&ex,sizeof(example),1,fp);
		printf("\n");
	}
	}
	else
	{
		for (int i=0;i<n;i++)
		{
		
		while(fread(&ex,sizeof(example),1,fp)!=EOF)
		{
	~ˆprintf("%s %s %d",ex.name,ex.address,ex.a);
		}
	}
	}
}
