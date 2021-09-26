#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>


typedef struct
{
int day,month,year;
}date;


typedef struct
[
char ad1[50],ad2[50],ahno[10],postcode[7];
}address;


typedef struct
{
char empid[20],pass[20],fname[0],sname[30],emailid[20],contact[11];
char dept,designn,status,worktype;
date dat[3];
address ad;
enum{male,female,transgender} gender;
float basicsal;
int nodays;
}employee_details;


int main()
{
char adminpass[20];

FILE *fp=fopen("mini.txt","r");

if(fp == NULL)
{
	printf("You dont have password for admin,create one!");
	printf("Admin Pass:");
	scanf("%s",adminpass);
	fclose(fp);
	fp=fopen("mini.txt","w");
	fprintf(fp,"%s",adminpass);
	fclose(fp);
}

employee_details emp[100000];

int num;                   /*n = number of employees/structures*/

printf("\t\t\tWELCOME TO PAYROLL MANAGEMENT");

int a1;
printf("Press\n1.Admin\n2.User\n3.exit");
scanf("%d",&a1);

while(a1!=3)
{
	if(a1==1)
	{
		char tempstr1[50];
		printf("Password:");
		scanf("%s",tempstr);
		if(strcmp(adminpass,tempstr)==0)
		{
			admin(&emp,&n);
		}
	}
	else if(a1==2)
	{
		user(&emp,&n);
	}
	else if(a1==3)
	{
		exit(0);
	}
	else
	{
		printf("Invalid Input");
	}
	printf("Press\n1.Admin\n2.User\n3.exit");
	scanf("%d",&a1);
}
}



void user(employee_details *emp,int *n)
{
	int tempnum;
	char tempstr3[50];
	
	int a1,b1,b2=0;
	
	printf("Press\n1.Login(if you already have a record)\n2.Signup(To create a new employee record)\n3.exit");
	scanf("%d",&a2);
	
	if(a2==1)
	{
		printf("Userid:");
		scanf("%d",tempnum);
		FILE *fp;
		fp=fopen("mini.txt","r");
		for(int i=0;i<n;i++)
		{
			fread(empid,sizeof(employee_details),1,fp);
			if(i.empid==tempnum)
			{
				b1=i;
				b2=1;
				break;
			}
		}
		fclose(fp);
		
		if(b2==0)
		{
			printf("Username is not available!");
			
			
			
			

















		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		

