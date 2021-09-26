#include<stdio.h>
#include<string.h>
typedef struct 
{
	char name[10];
	int ra;
}salary;
void main()
{
	int a;
	printf("a:");
	scanf("%d",&a);
	if(a==1)
	{
	FILE *fp;
	fp=fopen("copy.txt","w");
	
		
	salary sal[10];
	for(int i=0;i<3;i++)
	{
		printf("name,sal:");
		scanf("%s %d",sal[i].name,&sal[i].ra);
		fprintf(fp,"name:%s\t\tsal:%d",sal[i].name,sal[i].ra);
		fprintf(fp,"\n");
	}
	fclose(fp);
}
	if(a==2)
	{
		
		char name[20];
		int ras,length;
		FILE *fp1;
		fp1=fopen("copy.txt","r");
		while(fscanf(fp1,"name:%s\t\tsal:%d",name,&ras)!=EOF)
		{
			length=ftell(fp1);
			printf("%d",length);
			printf("%s %d",name,ras);
			fscanf(fp1,"\n");
		}
	}
}
