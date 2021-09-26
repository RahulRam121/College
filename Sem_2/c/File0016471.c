#include<stdio.h>
#include<string.h>
int n;
struct phonebook
{
	char name[30],address[100],phno[11];
}pb[100];
int main()
{
	FILE *fp1;
	fp1=fopen("num1.txt","r");
	fscanf(fp1,"%d",&n);
	fclose(fp1);
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
	FILE *fp1;
	fp1=fopen("num1.txt","w+");
	fprintf(fp1,"%d",n);
	fclose(fp1);
	fp=fopen("Phonebook.dat","ab");
	printf("Enter Name:");
	scanf("%s",pb[n-1].name);

	printf("Enter Address:");
	scanf("%s",pb[n-1].address);

	printf("Enter telephone num:");
	scanf("%s",pb[n-1].phno);
	fwrite(&pb[n-1],sizeof(struct phonebook),1,fp);
	fclose(fp);
	printf("Continue(y/n)?:");
	scanf(" %c",&ch);
	}
	printf("List updated!\n");
}


void modify()
{
	FILE *fp1;
	fp1=fopen("num1.txt","r");
	fscanf(fp1,"%d",&n);
	fclose(fp1);
	int x,y;
	x=search();
	if (x == -1)
	{
		return;
	}
	FILE *fp;
	fp=fopen("Phonebook.txt","ab");
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
	fwrite(&pb,sizeof(struct phonebook),n,fp);
	printf("Modified Sucessfully!\n");
	fclose(fp);
}

void displaysel()
{
	FILE *fp1;
	fp1=fopen("num1.txt","r");
	fscanf(fp1,"%d",&n);
	fclose(fp1);
	int x;
	x=search();
	if (x == -1)
	{
		return;
	}
	FILE *fp;
	fp=fopen("Phonebook.dat","rb");
	fread(pb,sizeof(struct phonebook),n,fp);
	
	printf("Name:%s\nAddress:%s\nTelephone Number:%s\n",pb[x].name,pb[x].address,pb[x].phno);
	fclose(fp);
}

void displayall()
{
	FILE *fp1;
	fp1=fopen("num1.txt","r");
	fscanf(fp1,"%d",&n);
	fclose(fp1);
	FILE *fp;
	fp=fopen("Phonebook.dat","rb");
	fread(pb,sizeof(struct phonebook),n,fp);
	for(int i=0;i<n;i++)
	{
		printf("Name:%s\nAddress:%s\nTelephone Number:%s\n",pb[i].name,pb[i].address,pb[i].phno);
	}
	fclose(fp);
}

int search()
{
	FILE *fp1;
	fp1=fopen("num1.txt","r");
	fscanf(fp1,"%d",&n);
	fclose(fp1);
	FILE *fp;
	fp=fopen("Phonebook.dat","rb");
	fread(pb,sizeof(struct phonebook),n,fp);
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



























	switch(u11)
		{
			case 1:
				switch(u12)
				{
					case 1:
						printf("Manager:");
						scanf("%d",&tmod);
						sal[0].man=tmod;
						return;
					case 2:
						printf("Assistant Manager:");
						scanf("%d",&sal[0].asman);return;
					case 3:	
						printf("Auditor:");	
						scanf("%d",&sal[0].audi);return;
					case 4:
						printf("HR:");	
						scanf("%d",&sal[0].hr);return;
					case 5:
						printf("Worker:");	
						scanf("%d",&sal[0].wor);return;
					default:
						printf("Invalid input");
					}
			case 2:
				switch(u12)
				{
					case 1:
						printf("Manager:");
						scanf("%d",&sal[1].man);return;
					case 2:
						printf("Assistant Manager:");
						scanf("%d",&sal[1].asman);return;
					case 3:	
						printf("Auditor:");	
						scanf("%d",&sal[1].audi);return;
					case 4:
						printf("HR:");	
						scanf("%d",&sal[1].hr);return;
					case 5:
						printf("Worker:");	
						scanf("%d",&sal[1].wor);return;
					default:
						printf("Invalid input");
					}
			case 3:
				switch(u12)
				{
					case 1:
						printf("Manager:");
						scanf("%d",&sal[2].man);return;
					case 2:
						printf("Assistant Manager:");
						scanf("%d",&sal[2].asman);return;
					case 3:	
						printf("Auditor:");	
						scanf("%d",&sal[2].audi);return;
					case 4:
						printf("HR:");	
						scanf("%d",&sal[2].hr);return;
					case 5:
						printf("Worker:");	
						scanf("%d",&sal[2].wor);return;
					default:
						printf("Invalid input");
					}
			case 4:
				switch(u12)
				{
					case 1:
						printf("Manager:");
						scanf("%d",&sal[3].man);return;
					case 2:
						printf("Assistant Manager:");
						scanf("%d",&sal[3].asman);return;
					case 3:	
						printf("Auditor:");	
						scanf("%d",&sal[3].audi);return;
					case 4:
						printf("HR:");	
						scanf("%d",&sal[3].hr);return;
					case 5:
						printf("Worker:");	
						scanf("%d",&sal[3].wor);return;
					default:
						printf("Invalid input");
						return;
					}
			default:
				printf("Invalid input");
				return;
			}
