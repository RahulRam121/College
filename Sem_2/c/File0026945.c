#include<stdio.h>
#include<string.h>
#include<stdlib.h>

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
	int dept,designation,empid;
	char status,worktype,gender;
	char pass[20],fname[100],sname[100],email_id[100];
	address ad;
	date d;
}payroll;

typedef struct
{
	int man,asman,audi,hr,wor;
}salary;

int search(payroll *pay,int n2);
void admin(payroll *pay,int *n);
void a_changepass();
void a_modemp(payroll *pay,int n1);
void cmodsal();
void user(payroll *pay,int *n);
void userin(payroll *pay,int i,int num);
void display(payroll *pay,int n4);

salary sal[4];

int main()
{	
void admin(payroll *pay,int *n);
int n;	
	
FILE *ap;
ap=fopen("adminpass.txt","a+");
char adminpass[20];


if(ap == '\0')
{
	printf("You dont have password for admin,create one!\n");
	printf("Admin Pass:");
	scanf("%s",adminpass);
	fprintf(ap,"%s",adminpass);
	fclose(ap);
}

payroll pay[1000];

FILE *fp1;
fp1=fopen("num1.txt","r");
fscanf(fp1,"%d",&n);
fclose(fp1);

printf("\t\t\tWELCOME TO PAYROLL MANAGEMENT\n");

int a;
printf("Press\n1.Admin\n2.User\n3.exit\nEnter:");
scanf("%d",&a);

while(a!=3)
{
	if(a==1)
	{
		ap=fopen("adminpass.txt","r");
		char tempstr1[50];
		x:
		printf("Password:");
		scanf("%s",tempstr1);
		
		fscanf(ap,"%s",adminpass);
		
		if(strcmp(adminpass,tempstr1)==0)
		{
			admin(&pay,&n);
		}
		else
		{
			printf("Wrong Password!\n");
			goto x;
		}
		fclose(ap);
	}
	else if(a==2)
	{
		user(&pay,&n);
	}
	else if(a==3)
	{
		exit(0);
	}
	else
	{
		printf("Invalid Input\n");
	}
	printf("Press\n1.Admin\n2.User\n3.exit\nEnter:");
	scanf("%d",&a);
	
}
}

void admin(payroll *pay,int *n)
{
	int e1;
	printf("Press\n1.Change password for admin.\n2.Modify employee details.\n3.Modify Salary for dept and its designation.\n4.Display All or Selected records.\n5.exit.\nEnter:");
	scanf("%d",&e1);
	while(e1!=5)
	{
		if(e1==1)
		{
			a_changepass();
		}
		else if(e1==2)
		{
			a_modemp(pay,*n);
		}
		else if(e1==3)
		{
			cmodsal();
		}
		else if(e1==4)
		{
			display(&(*pay),*n);
		}
		else if(e1==5)
		{
			return;
		}
		else
		{
			printf("Invalid Input!\n");	
		}
		printf("Press\n1.Change password for admin.\n2.Modify employee details.\n3.Create or Modify Salary for dept and its designation.\n4.Display All or Selected records.\n5.exit.\nEnter:");
		scanf("%d",&e1);
	}
}

void display(payroll *pay,int n4)
{
	int a2;
	printf("\n1.Print all records\n2.Print particular record\n3.Exit\nEnter:");
	scanf("%d",&a2);
	while(a2!=3)
	{
		
		if(a2==1)
		{
			printf("Displaying all records...\n");
			FILE *fpm9;
			fpm9=fopen("mini.dat","rb");
			fread(pay,sizeof(payroll),n4,fpm9);
			for(int i=0;i<n4;i++)
			{
				printf("EMP_ID:%d\t\tPassword:%s\nName:%s %s\nEmail_id:%s\n",pay[i].empid,pay[i].pass,pay[i].fname,pay[i].sname,pay[i].email_id);
				printf("Gender:");
				if(pay[i].gender== 'm')
				{
					printf("Male\n");
				}
				else if(pay[i].gender == 'f')
				{
					printf("Female\n");
				}
				else
				{
					printf("Transgender\n");
				}
				printf("Department:");
				switch(pay[i].dept)
				{
					case 1:printf("Software\n");break;
					case 2:printf("Hardware\n");break;
					case 3:printf("Security\n");break;
					case 4:printf("Wespon Handling\n");break;
					default:break;
				}
				printf("Designation:");
				switch(pay[i].designation)
				{
					case 1:printf("Manager\n");break;
					case 2:printf("Assistant Manager\n");break;
					case 3:printf("Auditor\n");break;
					case 4:printf("HR\n");break;
					case 5:printf("Worker\n");break;
					default:break;
				}
				printf("Worktype:");
				if(pay[i].worktype=='a')
				{
					printf("Daily\n");
				}
				else
				{
					printf("Monthly\n");
				}
				printf("Status:");
				if(pay[i].status=='a')
				{
					printf("Active\n");
				}
				else
				{
					printf("Retired\n");
				}
				printf("\n");
			}
			fclose(fpm9);
		}
		else if(a2==2)
		{
			FILE *fpk;
			fpk=fopen("mini.dat","rb");
			fread(pay,sizeof(payroll),n4,fpk);
			int empid4,q1,q2=0;
			m:
			printf("Enter EMP_ID:");
			scanf("%d",&empid4);
			for(int i=0;i<n4;i++)
			{
				if(empid4==pay[i].empid)
				{
					q1=i;
					q2=1;
					break;
				}
			}
			if(q2==0)
			{
				printf("No EMP_ID found!\n");
				int q3;
				printf("\n1.Try Again\n2.Exit\nEnter:");
				scanf("%d",&q3);
				if(q3==1)
				{
					goto m;
				}
				else
				{
					return;
				}
			}
				printf("EMP_ID:%d\t\tPassword:%s\nName:%s %s\nEmail_id:%s\n",pay[q1].empid,pay[q1].pass,pay[q1].fname,pay[q1].sname,pay[q1].email_id);
				printf("Gender:");
				if(pay[q1].gender== 'm')
				{
					printf("Male\n");
				}
				else if(pay[q1].gender == 'f')
				{
					printf("Female\n");
				}
				else
				{
					printf("Transgender\n");
				}
				printf("Department:");
				switch(pay[q1].dept)
				{
					case 1:printf("Software\n");break;
					case 2:printf("Hardware\n");break;
					case 3:printf("Security\n");break;
					case 4:printf("Wespon Handling\n");break;
					default:break;
				}
				printf("Designation:");
				switch(pay[q1].designation)
				{
					case 1:printf("Manager\n");break;
					case 2:printf("Assistant Manager\n");break;
					case 3:printf("Auditor\n");break;
					case 4:printf("HR\n");break;
					case 5:printf("Worker\n");break;
					default:break;
				}
				printf("Worktype:");
				if(pay[q1].worktype=='a')
				{
					printf("Daily\n");
				}
				else
				{
					printf("Monthly\n");
				}
				printf("Status:");
				if(pay[q1].status=='a')
				{
					printf("Active\n");
				}
				else
				{
					printf("Retired\n");
				}
		fclose(fpk);		
		}
		else if(a2==3)
		{
			return;
		}
		else
		{
			printf("Invalid Input!\n");
		}
		printf("\n1.Print all records\n2.Print particular record\n3.Exit\nEnter:");
		scanf("%d",&a2);
	}
}

void a_changepass()
{
	FILE *fpc;
	char tempstr[20];
	fpc=fopen("adminpass.txt","w");
	printf("Enter the new password:");
	scanf("%s",tempstr);
	fprintf(fpc,"%s",tempstr);
	printf("Password changed successfully!\n");
	fclose(fpc);	
}

void a_modemp(payroll *pay,int n1)
{	
	FILE *fpm5;
	fpm5=fopen("mini.dat","rb");
	fread(pay,sizeof(payroll),n1,fpm5);
	fclose(fpm5);
	int v6,v3,v7=0,empid3;
	m:
	
	printf("Enter EMP_ID:");
	scanf("%d",&empid3);
		for(int i=0;i<n1;i++)
	{
		if(empid3==pay[i].empid)
		{
			v6=i;
			v7=1;
			break;
		}
	}
	if(v7==0)
	{
		printf("No EMP_ID found!\n");
		int v8;
		printf("\n1.Try Again\n2.Exit\n");
		scanf("%d",&v8);
		if(v8==1)
		{
			goto m;
		}
		else
		{
			return;
		}
	}
	printf("Press to change\n1.password\n2.First name\n3.Last name\n4.Email_id\n5.Address\n6.DOB\n7.status\n8.Dept\n9.Designation\n10.Worktype\n11.exit\n");
	scanf("%d",&v3);
	if(v3!=11)
	{
		fpm5=fopen("mini.dat","rb");
		fread(pay,sizeof(payroll),n1,fpm5);
		
		switch(v3)
		{
			case 1:
				printf("New PASSWORD:");
				scanf("%s",pay[v6].pass);
				break;
			case 2:
				printf("First name:");
				scanf("%s",pay[v6].fname);
				break;
			case 3:
				
				printf("Last name:");
				scanf("%s",pay[v6].sname);
				break;
			case 4:
				
				printf("Email id:");
				scanf("%s",pay[v6].email_id);
				break;
			case 5:
				printf("HOUSE_NO LOCATION CITY PINCODE:\n");
				scanf("%d %s %s %d",&pay[v6].ad.houseno,pay[v6].ad.ad1,pay[v6].ad.ad2,&pay[v6].ad.pincode);break;
			case 6:
				printf("DD MM YY OF BIRTH:\n");
				scanf("%d %d %d",&pay[v6].d.date,&pay[v6].d.month,&pay[v6].d.year);break;
			case 7:
				printf("STATUS(ACTIVE(a) OR RETIRED(r)):\n");
				scanf(" %c",&pay[v6].status);break;
			case 8:
				printf("DEPARTMENT:\n");
				printf("Press\n\" 1 \" ->Software\n\" 2 \" ->Hardware\n\" 3 \" ->Security\n\" 4 \" ->Weapon Handling\n");
				scanf("%d",&pay[v6].dept);break;
			case 9:
				printf("DESIGNATION:\n");
				printf("Press\n\" 1 \" ->Manager\n\" 2 \"->Assistant Manager\n\" 3 \"->Auditor\n\" 4 \"->HR\n\" 5 \"->worker\n");
				scanf("%d",&pay[v6].designation);break;
			case 10:
				printf("Press\n\" a \" ->daily\n\" b \" ->monthly\n");
				scanf(" %c",&pay[v6].worktype);break;
			default:
				printf("Invalid Input!");
				
			
		}
	printf("Updated Successfully!\n");
	fclose(fpm5);
	FILE *fpm6;
	fpm6=fopen("mini.dat","wb");
	fwrite(pay,sizeof(payroll),n1,fpm6);
	fclose(fpm6);
	}
		
}

void cmodsal()
{
	int u8;
	printf("Press\n1.create\n2.modify\n3.exit\nEnter:");
	scanf("%d",&u8);
	if(u8==1)
	{
		FILE *fpm5;
		fpm5=fopen("salary.dat","wb");
		for(int i=0;i<4;i++)
		{
		if(i==0)
		{
			printf("SOFTWARE DEPT\n");
		}
		else if(i==1)
		{
			printf("HARDWARE DEPT:");
		}
		else if(i==2)
		{
			printf("SECURITY:");
		}
		else
		{
			printf("WEAPON HANDLING:");
		}
		printf("Manager:");
		scanf("%d",&sal[i].man);
		printf("Assistant Manager:");
		scanf("%d",&sal[i].asman);
		printf("Auditor:");
		scanf("%d",&sal[i].audi);
		printf("HR:");
		scanf("%d",&sal[i].hr);
		printf("Worker:");
		scanf("%d",&sal[i].wor);	
		}
		fwrite(&sal,sizeof(salary),4,fpm5);
		fclose(fpm5);	
	}
	else
	{
		int tmod;
		int u11,u12;
		FILE *fpcm;
		fpcm=fopen("salary.dat","rb");
		fread(sal,sizeof(salary),4,fpcm);
		printf("Press\n1.Software\n2.Hardware\n3.Security\n4.Weapon Handling\nEnter:");
		scanf("%d",&u11);
		printf("Press\n1.Manager\n2.Assistant Manager\n3.Auditor\n4.HR\n\5.worker\nEnter:");
		scanf("%d",&u12);
		if(u11==1)
		{
			switch(u12)
			{
				case 1:
					printf("Manager:");
					scanf("%d",&tmod);
					sal[0].man=tmod;
					break;
				case 2:
					printf("Assistant Manager:");
					scanf("%d",&sal[0].asman);break;
				case 3:	
					printf("Auditor:");	
					scanf("%d",&sal[0].audi);break;
				case 4:
					printf("HR:");	
					scanf("%d",&sal[0].hr);break;
				case 5:
					printf("Worker:");	
					scanf("%d",&sal[0].wor);break;
				default:
					printf("Invalid input");
			}
		}
		else if(u11==2)
		{
			switch(u12)
			{
				case 1:
					printf("Manager:");
					scanf("%d",&sal[1].man);break;
				case 2:
					printf("Assistant Manager:");
					scanf("%d",&sal[1].asman);break;
				case 3:	
					printf("Auditor:");	
					scanf("%d",&sal[1].audi);break;
				case 4:
					printf("HR:");	
					scanf("%d",&sal[1].hr);break;
				case 5:
					printf("Worker:");	
					scanf("%d",&sal[1].wor);break;
				default:
					printf("Invalid input");
			}
		}
		else if(u11==3)
		{
			switch(u12)
			{
				case 1:
					printf("Manager:");
					scanf("%d",&sal[2].man);break;
				case 2:
					printf("Assistant Manager:");
					scanf("%d",&sal[2].asman);break;
				case 3:	
					printf("Auditor:");	
					scanf("%d",&sal[2].audi);break;
				case 4:
					printf("HR:");	
					scanf("%d",&sal[2].hr);break;
				case 5:
					printf("Worker:");	
					scanf("%d",&sal[2].wor);break;
				default:
					printf("Invalid input");
			}
		}
		else if(u11==4)
		{
			switch(u12)
			{
				case 1:
					printf("Manager:");
					scanf("%d",&sal[3].man);break;
				case 2:
					printf("Assistant Manager:");	
					scanf("%d",&sal[3].asman);break;
				case 3:	
					printf("Auditor:");	
					scanf("%d",&sal[3].audi);break;
				case 4:
					printf("HR:");	
					scanf("%d",&sal[3].hr);break;
				case 5:
					printf("Worker:");	
					scanf("%d",&sal[3].wor);break;
				default:
					printf("Invalid input");
			}
		}
		else
		{
			printf("Invalid input\n");
			return;
		}
		printf("Updated Successfully!\n");
		fclose(fpcm);
	}
	
	FILE *fpcm1;
	fpcm1=fopen("salary.dat","w");
	fwrite(&sal,sizeof(salary),4,fpcm1);
	fclose(fpcm1);
}

void user(payroll *pay,int *n)
{
FILE *fpu;
fpu=fopen("mini.dat","ab");

char pass1[20];

printf("\t\tWELCOME TO PAYROLL MANAGEMENT\n");
printf("1.SIGN_UP\t\t\t\t 2.LOGIN\n");
printf("\n");
printf("ENTER:");
int u1;
scanf("%d",&u1);
if(u1==1)
	{
	printf("ENTER YOUR fIRST NAME:\n");
	scanf("%s",pay[*n].fname);
	printf("ENTER YOUR SECOND NAME:\n");
	scanf("%s",pay[*n].sname);
	printf("CREATE A PASSWORD:\n");
	scanf("%s",pay[*n].pass);
	printf("CONFIRM AGAIN:\n");
	scanf("%s",pass1);
	printf("DD MM YY OF BIRTH:\n");
	scanf("%d %d %d",&pay[*n].d.date,&pay[*n].d.month,&pay[*n].d.year);
	printf("STATUS(ACTIVE(a) OR RETIRED(r)):\n");
	scanf(" %c",&pay[*n].status);
	printf("EMAIL_ID:\n");
	scanf("%s",pay[*n].email_id);
	printf("HOUSE_NO,LOCATION,CITY,PINCODE:\n");
	scanf("%d %s %s %d",&pay[*n].ad.houseno,pay[*n].ad.ad1,pay[*n].ad.ad2,&pay[*n].ad.pincode);
	printf("DESIGNATION:\n");
	printf("Press\n\" 1 \" ->Manager\n\" 2 \"->Assistant Manager\n\" 3 \"->Auditor\n\" 4 \"->HR\n\" 5 \"->worker\n");
	scanf("%d",&pay[*n].designation);
	printf("GENDER\n");
	printf("Press\n\" m \" ->Male\n\" f \" ->Female\n\" t \" ->Transgender\n");
	scanf(" %c",&pay[*n].gender);
	printf("DEPARTMENT:\n");
	printf("Press\n\" 1 \" ->Software\n\" 2 \" ->Hardware\n\" 3 \" ->Security\n\" 4 \" ->Weapon Handling\n");
	scanf("%d",&pay[*n].dept);
	printf("Press\n\" a \" ->daily\n\" b \" ->monthly\n");
	scanf(" %c",&pay[*n].worktype);
	pay[*n].empid=10000+*n+1;
	x:
	if(strcmp(pay[*n].pass,pass1)!=0)
		{
		printf(" SRY PASSWORD WRONG\n");
		printf("TRY AGAIN :\n");
		scanf("%s",pass1);
		if(strcmp(pay[*n].pass,pass1)!=0)
			goto x;
		}
	
	else
		{
		printf("REGISTRATION SUCCESSFUL");
		fwrite(&pay[*n],sizeof(payroll),1,fpu);
		*n=*n+1;
		FILE *fp1;
		fp1=fopen("num1.txt","w");
		fprintf(fp1,"%d",*n);
		fclose(fp1);
		int v20=*n,v21=((*n)-1);
		userin(&(*pay),v21,v20);
		fclose(fpu);
		}
}
else
{
	FILE *fpu1;
	fpu1=fopen("mini.dat","rb");
	fread(pay,sizeof(payroll),*n,fpu1);
	char pass2[20];
	int empid1;
	int v1,x3=0;
	n:
	printf("ENTER YOUR EMP_ID:\n");
	scanf("%d",&empid1);
	printf("PASSWORD:\n");
	scanf("%s",pass2);
	for(int i=0;i<*n;i++)
	{
	if(strcmp(pay[i].pass,pass2)==0 || pay[i].empid==empid1)
	{
		x3==1;
		v1=i;
		printf("ARE U A ROBOT?\n");
		printf("CAPTCHA: ");
		char u2[20]="answer";
		printf("%s\n",u2);
		char u3[20];
		m:
		printf("ENTER CAPTCHA: ");
		scanf("%s",u3);
		if(strcmp(u3,u2)==0)
		{
			printf("LOGIN SUCCESSFUL..LOADING....\n");
			printf("ENTER 1 TO CONTINUE:");
			int u5;
			scanf("%d",&u5);
			if(u5==1)
			{
				userin(&(*pay),v1,*n);
				return;
			}
			else
			{
				return;	
			}
		}
		else
		{
			printf("WRONG\n");
			goto m;
		}	
	}
	}
	if(x3==0)
	{
		printf("User ID not founnd!\n");
		int x4;
		printf("1.Try again\n2.Exit\nEnter:");
		scanf("%d",&x4);
		if(x4==1)
		{
			goto n;
		}
		else
		{
			return;
		}
	}
	}

}

void userin(payroll *pay,int i,int num)
{
	int v1;
	float bp;
	float da,hra,pf,cca=1000,insurance=2000,gross_pay,netpay,ded;
	printf("Press\n1.Modify your details\n2.Get payslip\n3.exit\n");
	scanf("%d",&v1);
	if(v1==1)
	{
	FILE *fpm5;
	int v3;
	fpm5=fopen("mini.dat","rb");
	fread(pay,sizeof(payroll),num,fpm5);
	printf("Press to change\n1.password\n2.First name\n3.Last name\n4.Email_id\n5.Address\n6.DOB\n7.status\n8.Dept\n9.Designation\n10.Worktype\n11.exit\n");
	scanf("%d",&v3);
	while(v3!=11)
	{
		switch(v3)
		{
			case 1:
				printf("New PASSWORD:");
				scanf("%s",pay[i].pass);
				break;
			case 2:
				printf("First name:");
				scanf("%s",pay[i].fname);
				break;
			case 3:
				
				printf("Last name:");
				scanf("%s",pay[i].sname);
				break;
			case 4:
				
				printf("Email id:");
				scanf("%s",pay[i].email_id);
				break;
			case 5:
				printf("HOUSE_NO,LOCATION,CITY,PINCODE:\n");
				scanf("%d %s %s %d",&pay[i].ad.houseno,pay[i].ad.ad1,pay[i].ad.ad2,&pay[i].ad.pincode);break;
			case 6:
				printf("DD MM YY OF BIRTH:\n");
				scanf("%d %d %d",&pay[i].d.date,&pay[i].d.month,&pay[i].d.year);break;
			case 7:
				printf("STATUS(ACTIVE(a) OR RETIRED(r)):\n");
				scanf(" %c",&pay[i].status);break;
			case 8:
				printf("DEPARTMENT:\n");
				printf("Press\n\" 1 \" ->Software\n\" 2 \" ->Hardware\n\" 3 \" ->Security\n\" 4 \" ->Weapon Handling\n");
				scanf("%d",&pay[i].dept);break;
			case 9:
				printf("DESIGNATION:\n");
				printf("Press\n\" 1 \" ->Manager\n\" 2 \"->Assistant Manager\n\" 3 \"->Auditor\n\" 4 \"->HR\n\" 5 \"->worker\n");
				scanf("%d",&pay[i].designation);break;
			case 10:
				printf("Press\n\" a \" ->daily\n\" b \" ->monthly\n");
				scanf(" %c",&pay[i].worktype);break;
			default:
				printf("Invalid Input!");
				
			
		}
	printf("Updated Successfully!\n");
	printf("Press to change\n1.password\n2.First name\n3.Last name\n4.Email_id\n5.Address\n6.DOB\n7.status\n8.Dept\n9.Designation\n10.Worktype\n11.exit\nEnter:");
	scanf("%d",&v3);
	}
	fclose(fpm5);
	FILE *fpm6;
	fpm6=fopen("mini.dat","wb");
	fwrite(pay,sizeof(payroll),num,fpm6);
	fclose(fpm6);
	return;	
	}
	
	else if(v1==2)
	{
		FILE *fpm4,*fpm5;
		fpm5=fopen("salary.dat","rb");
		fread(sal,sizeof(salary),4,fpm5);
		fpm4=fopen("mini.dat","rb");
		fread(pay,sizeof(payroll),num,fpm4);
		if(pay[i].dept==1)
		{
		
			switch(pay[i].designation)
			{
				case 1:
					bp=sal[0].man;break;
				case 2:
					bp=sal[0].asman;break;
				case 3:
					bp=sal[0].audi;break;
				case 4:
					bp=sal[0].hr;break;
				case 5:
					bp=sal[0].wor;break;
				default:
					printf("Invalid Input!\n");
					return;
			}
		}
		else if(pay[i].dept==2)
		{
			switch(pay[i].designation)
			{
				case 1:
					bp=sal[1].man;break;
				case 2:
					bp=sal[1].asman;break;
				case 3:
					bp=sal[1].audi;break;
				case 4:
					bp=sal[1].hr;break;
				case 5:
					bp=sal[1].wor;break;
				default:
					printf("Invalid Input!\n");
					return;
			}
		}
		else if(pay[i].dept==3)
		{
			switch(pay[i].designation)
			{
				case 1:
					bp=sal[2].man;break;
				case 2:
					bp=sal[2].asman;break;
				case 3:
					bp=sal[2].audi;break;
				case 4:
					bp=sal[2].hr;break;
				case 5:
					bp=sal[2].wor;break;
				default:
					printf("Invalid Input!\n");
					return;
			}
		}
		else if(pay[i].dept==4)
		{
			switch(pay[i].designation)
			{
				case 1:
					bp=sal[3].man;break;
				case 2:
					bp=sal[3].asman;break;
				case 3:
					bp=sal[3].audi;break;
				case 4:
					bp=sal[3].hr;break;
				case 5:
					bp=sal[3].wor;break;
				default:
					printf("Invalid Input!\n");
					return;
			}
		}
		fclose(fpm5);
		fclose(fpm4);
	}
	else if(v1==3)
	{
		return;
	}
	else
	{
		printf("Invalid Input!\n");
		return;
	}	
	da=0.8*bp;
    hra=0.1*bp;
    pf=0.12*bp;
	gross_pay=bp+da+hra+cca;
	ded=insurance+pf;
	netpay=gross_pay-ded;
	printf("\t\t\tSALARY SLIP OF THE EMPLOYEE\n");
	printf("EMPLOYEE DETAILS\t\t\t\tEARNINGS");
	printf("\n");
	printf("First Name:%s\n",pay[i].fname);
	printf("Last Name:%s\n",pay[i].sname);
	printf("Emp_id:%d\n",pay[i].empid);
	printf("email id:%s\n",pay[i].email_id);
	printf("Gender:");
	if(pay[i].gender== 'm')
	{
		printf("Male\n");
	}
	else if(pay[i].gender == 'f')
	{
		printf("Female\n");
	}
	else
	{
		printf("Transgender\n");
	}
	printf("Department:");
	switch(pay[i].dept)
	{
		case 1:printf("Software\n");break;
		case 2:printf("Hardware\n");break;
		case 3:printf("Security\n");break;
		case 4:printf("Wespon Handling\n");break;
		default:break;
	}
	printf("Designation:");
	switch(pay[i].designation)
	{
		case 1:printf("Manager\n");break;
		case 2:printf("Assistant Manager\n");break;
		case 3:printf("Auditor\n");break;
		case 4:printf("HR\n");break;
		case 5:printf("Worker\n");break;
		default:break;
	}
	printf("Worktype:");
	if(pay[i].worktype=='a')
	{
		printf("Daily\n");
	}
	else
	{
		printf("Monthly\n");
	}
	printf("Status:");
	if(pay[i].status=='a')
	{
		printf("Active\n");
	}
	else
	{
		printf("Retired\n");
	}
	printf("\t\t\t\tBasic pay:\t%.2f\n",bp);
	printf("\t\t\t\tda:\t\t%.2f\n",da);
	printf("\t\t\t\thra:\t\t%.2f\n",hra);
	printf("\t\t\t\tpf:\t\t%.2f\n",pf);
	printf("\t\t\t\tcca:\t\t%.2f\n",cca);
	printf("\t\t\t\tInsurance:\t%.2f\n",insurance);
	printf("\t\t\t\tDeduction:\t%.2f\n",ded);
	printf("\t\t\t\tGrosspay:\t%.2f\n",gross_pay);
	printf("\n");
	printf("\t\t\tNETPAY OF THE EMPLOYEE : %.2f\n",netpay);
	
}

int search(payroll *pay,int n2)
{
	FILE *fpm;
	fpm=fopen("mini.dat","rb");
	fread(pay,sizeof(payroll),n2,fpm);
	int empid2,u10=0;
	printf("Enter the employee id :");
	scanf("%d",&empid2);
	for(int i=0;i<n2;i++)
	{
		if(empid2==pay[i].empid)
		{
			u10=1;
			fclose(fpm);
			return i;
		
		}
	}
	if(u10==0)
	{
		printf("Employee id not found!\n");
		fclose(fpm);
	}
}


