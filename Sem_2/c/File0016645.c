#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct example
{
	char name[20],address[20];
	int a;
	
};
void main()
{
	struct example ex;
	int n=0;
	FILE *fp;
	fp=fopen("xample.dat","w");
	if (fp == NULL)
     {
      fprintf(stderr, "\nError opening accounts.dat\n\n");
      exit (1);
     }


	while(n!=3)
	{
		scanf("%s", ex.name);
		scanf("%s", ex.address);
		scanf("%d", &ex.a);
		fwrite(&ex,sizeof(struct example),1,fp);
		n++;
	}
	fclose(fp);


}
