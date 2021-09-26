#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
	int date,month,year;
}date;


typedef struct 
{
	
	int houseno,pincode;
	char ad1[100],ad2[100];
}address;

typedef struct 
{
	int empid;
	char status,dept,designation,worktype,gender;
	char pass[20],fname[100],sname[100],email_id[100];
	address ad;
	date d;
}payroll;
void main()
{
		payroll pay[10];
		FILE *fp1;
		fp1 = fopen ("mini.dat","rb");
		if(fp1 == NULL)
		{
			fprintf(stderr, "\nError opening accounts.dat\n\n");
			exit(1);
		}
		fread(pay, sizeof(payroll), 3, fp1);
		
		for(int i=0;i<2;i++)
		{
		
		printf("%10s %10s %8d", pay[i].fname, pay[i].sname, pay[i].empid);
		printf("\n");
	}
}
