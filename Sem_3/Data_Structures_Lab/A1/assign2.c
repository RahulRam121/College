#include<stdio.h>
#include<string.h>

typedef struct 
{
	int regno,mark[5];
	char name[20];
}student;

void insertfront(student *s,int *n);
void insertlast(student *s,int *n);
void insertmiddle(student *s,int *n);
void search(student *s,int *n);
void delete(student *s,int *n);
void displayall(student *s,int *n);
void displaypnrec(student *s,int *n);




int main()
{
	student stu[20];
	int n=0;
	int sel;
	printf("Press\n1.Insert Record at front.\n2.Insert a record at the end of the list.\n3.Insert a record after a given Regno in the list.\n4.Search a given record in the list based on Name.\n5.Delete a given student record.\n6.Display all student's record.\n7.Display the previous and next record of a given student.\n8.Exit\nexit.\n");
	scanf("%d",&sel);
	while(sel!=8)
	{
		switch(sel)
		{
			case 1:insertfront(stu,&n);break;
			case 2:insertlast(stu,&n);break;
			case 3:insertmiddle(stu,&n);break;
			case 4:search(stu,&n);break;
			case 5:delete(stu,&n);break;
			case 6:displayall(stu,&n);break;
			case 7:displaypnrec(stu,&n);break;
			case 8:return 0;
			default:printf("Invalid Input!\n");
		}
	printf("Press\n1.Insert Record at front.\n2.Insert a record at the end of the list.\n3.Insert a record after a given Regno in the list.\n4.Search a given record in the list based on Name.\n5.Delete a given student record.\n6.Display all student's record.\n7.Display the previous and next record of a given student.\n8.Exit\nexit.\n");
	scanf("%d",&sel);	
	}
	return 0;
}
void insertfront(student s[],int *n)
{
	for(int i=*n;i>0;i--)
	{
		s[i]=s[i-1];
	}
	printf("New Student's Record:\n");
	printf("Enter the register number:");
	scanf("%d",&s[0].regno);
	printf("Enter the name of the Student:");
	scanf("%s",s[0].name);
	for(int j=0;j<5;j++)
	{
		printf("Enter the %dth mark:",j+1);
		scanf("%d",&s[0].mark[j]);
	}
	*n+=1;
}

void insertlast(student s[],int *n)
{
	printf("New Student's Record:\n");
	printf("Enter the register number:");
	scanf("%d",&s[*n].regno);
	printf("Enter the name of the Student:");
	scanf("%s",s[*n].name);
	for(int j=0;j<5;j++)
	{
		printf("Enter the %dth mark:",j+1);
		scanf("%d",&s[*n].mark[j]);
	}
	*n+=1;
}

void insertmiddle(student s[],int *n)
{
	int num,count=-1;
	printf("Enter the Register Number:");
	scanf("%d",&num);
	for(int i=0;i<*n;i++)
	{
		if(s[i].regno==num)
		{
			count=i;
			break;
		}
	}
	if(count==-1)
	{
		printf("Given Register Number not found!\n");
		return;
	}
	for(int k=*n;k>count;k--)
	{
		s[k]=s[k-1];
	}
	printf("New Student's Record:\n");
	printf("Enter the register number:");
	scanf("%d",&s[count+1].regno);
	printf("Enter the name of the Student:");
	scanf("%s",s[count+1].name);
	for(int j=0;j<5;j++)
	{
		printf("Enter the %dth mark:",j+1);
		scanf("%d",&s[count+1].mark[j]);
	}
	*n+=1;
}

void search(student s[],int *n)
{
	int pos=-1,i;
	char name1[20];
	printf("Enter the name of the student:");
	scanf("%s",name1);
	for(i=0;i<*n;i++)
	{
		if(strcmp(s[i].name,name1)==0)
		{
				pos=i;
		}
	}
	if(pos==-1)
	{
		printf("Given Name is not found!\n");
		return;
	}
	printf("Record is found in %d th position\n",i);
	printf("Register Number : %d\n",s[pos].regno);
	printf("Name : %s\n",s[pos].name);
	for(int j=0;j<5;j++)
	{
		printf("Mark %d : %d\n",j+1,s[pos].mark[j]);
	}
}

void delete(student s[],int *n)
{
	int tempno,count=-1;
	printf("Enter the Register number of the student you want to delete:");
	scanf("%d",&tempno);
	for(int i=0;i<*n;i++)
	{
		if(s[i].regno==tempno)
		{
			count=i;
			break;
		}
	}
	if(count==-1)
	{
		printf("Given Register Number not found!\n");
		return;
	}
	for(int j=count;j<*n-1;j++)
	{
			s[j]=s[j+1];
	}
	*n-=1;
}

void displayall(student s[],int *n)
{
	for(int i=0;i<*n;i++)
	{
		printf("Record :%d\n",i+1);
		printf("Register Number : %d\n",s[i].regno);
		printf("Name : %s\n",s[i].name);
		for(int j=0;j<5;j++)
		{
			printf("Mark %d : %d\n",j+1,s[i].mark[j]);
		}
	}
}
void displaypnrec(student s[],int *n)
{
	int num,count=-1,i;
	printf("Enter the Register Number:");
	scanf("%d",&num);
	for(i=0;i<*n;i++)
	{
		if(s[i].regno==num)
		{
			count=i;
			break;
		}
	}
	if(count==-1)
	{
		printf("Given Register Number not found!\n");
		return;
	}
	if(i==0)
	{
		printf("Record is found in the 1st position.\nDisplaying 2nd Record...\n");
		printf("Register Number : %d\n",s[1].regno);
		printf("Name : %s\n",s[1].name);
		for(int j=0;j<5;j++)
		{
			printf("Mark %d : %d\n",j+1,s[1].mark[j]);
		}
	}
	else if(i==*n-1)
	{
		printf("Record is found in the last position.\nDisplaying n-1th Record...\n");
		printf("Register Number : %d\n",s[*n-1].regno);
		printf("Name : %s\n",s[*n-1].name);
		for(int j=0;j<5;j++)
		{
		printf("Mark %d : %d\n",j+1,s[*n-2].mark[j]);
		}
	}
	else
	{
		printf("Record is found in the %dth position.\n",count+1);
		printf("Displaying %dth record...\n",count);
		printf("Register Number : %d\n",s[count-1].regno);
		printf("Name : %s\n",s[count-1].name);
		for(int j=0;j<5;j++)
		{
			printf("Mark %d : %d\n",j+1,s[count-1].mark[j]);
		}
		printf("Displaying %dth record...\n",count+2);
		printf("Register Number : %d\n",s[count+1].regno);
		printf("Name : %s\n",s[count+1].name);
		for(int j=0;j<5;j++)
		{
			printf("Mark %d : %d\n",j+1,s[count+1].mark[j]);
		}
	}
}






