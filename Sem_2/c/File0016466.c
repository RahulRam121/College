#include<stdio.h>
#include<string.h>
int n=0;
struct phonebook
{
	char name[30],address[100],phno[11];
}pb[100];
int main()
{
	void addeof();
	void modify();
	void displaysel();
	void displayall();
	int search();
	int s=1;
	printf("Press\n1.Add a New Record at end of a file.\n2.Modify an existing record.\n3.Retrve and display an entire record for a given name.\n4.List all names with their addresses and telephone numbers.\n5.Exit\n");
	scanf("%d",&s);
	while(s!=5)
	{
	switch(s)
	{
		case 1:addeof();
		break;
		case 2:modify();
		break;
		case 3:displaysel();
		break;
		case 4:displayall();
		break;
		case 5:return 0;
		default:printf("Enter a valid input:");
	}
	printf("Press\n1.Add a New Record at end of a file.\n2.Modify an existing record.\n3.Retrve and display an entire record for a given name.\n4.List all names with their addresses and telephone numbers.\n5.Exit\n");
	scanf("%d",&s);
	}
	return 0;
}
void addeof()
{
	char ch='y';
	while(ch=='y' || ch=='Y')
	{
	n+=1;
	FILE *fp;
	fp=fopen("Phonebook.txt","a");
	printf("Enter Name:");
	scanf("%s",pb[n-1].name);
	fprintf(fp,"%s",pb[n-1].name);
	fprintf(fp,"\t\t");
	printf("Enter Address:");
	scanf("%s",pb[n-1].address);
	fprintf(fp,"%s",pb[n-1].address);
	fprintf(fp,"\t\t");
	printf("Enter telephone num:");
	scanf("%s",pb[n-1].phno);
	fprintf(fp,"%s",pb[n-1].phno);
	fprintf(fp,"\n\n");
	fclose(fp);
	printf("Continue(y/n)?:");
	scanf(" %c",&ch);
	}
	printf("List updated!\n");
}


void modify()
{
	int x,y;
	x=search();
	if (x == -1)
	{
		return;
	}
	FILE *fp;
	fp=fopen("Phonebook.txt","w");
	printf("Press\n1.Edit Name\n2.Edit Address\n3.Edit Telephone number\n");
	scanf("%d",&y);
	if(y == 1)
	{
		printf("Enter Name:");
		scanf("%s",pb[x].name);

	}
	else if(y == 2)
	{
		printf("Enter Address:");
		scanf("%s",pb[x].address);
	}
	else if(y==3)
	{
		printf("Enter telephone num:");
		scanf("%s",pb[x].phno);
	}
	else
	{
		printf("Invalid Input");
	}
	printf("Modified Sucessfully!\n");
	fclose(fp);
}

void displaysel()
{
	int x;
	x=search();
	if (x == -1)
	{
		return;
	}
	FILE *fp;
	fp=fopen("Phonebook.txt","r");
	fscanf(fp,"%s\t%s\t%s\n",pb[x].name,pb[x].address,pb[x].phno);
	printf("Name:%s\nAddress:%s\nTelephone Number:%s\n",pb[x].name,pb[x].address,pb[x].phno);
	fclose(fp);
}

void displayall()
{
	FILE *fp;
	fp=fopen("Phonebook.txt","r");
	for(int i=0;i<n;i++)
	{
		printf("Name:%s\nAddress:%s\nTelephone Number:%s\n",pb[i].name,pb[i].address,pb[i].phno);
	}
	fclose(fp);
}

int search()
{
	FILE *fp;
	fp=fopen("Phonebook.txt","r");
	int x=0,y;
	char srch[30];
	printf("Enter the name of the person you want to search:");
	scanf("%s",srch);
	for(int i=0;i<n;i++)
	{
		if(strcmp(srch,pb[i].name) == 0)
		{
			y=i;
			x=1;
		}
	}
	fclose(fp);
	if (x == 0)
	{
		printf("The given name is not found!\n");
		y=-1;
	}
	return y;
}
