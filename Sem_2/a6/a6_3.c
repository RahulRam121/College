#include<stdio.h>
#include<string.h>
typedef struct
{
	int day;
	int month;
	int year;
}date;

typedef struct
{
	int rollno,age,rank;
	char name[50];
	int mark[5],totalmarks;
	date dat;
	enum {MALE,FEMALE,TRANSGENDER} gender;
}student;

int main()
{
student s[100];

int n,maxm;
printf("Enter the number of students:");
scanf("%d",&n);
printf("Enter the maximum total marks:");
scanf("%d",&maxm);
for (int i=0;i<n;i++)
{
inputs(&s,&i);
}
comrank(&s,n,maxm);
display(&s,n);
return 0;
}
void inputs(student *s,int *i)
{
int sum=0; 
char g[12];
printf("Enter the name of the %dth student:",*i+1);
scanf("%s",s[*i].name);
printf("Enter the rollno of the %dth student:",*i+1);
scanf("%d",&s[*i].rollno);
printf("Enter the age of the %dth student:",*i+1);
scanf("%d",&s[*i].age);
printf("Enter the birthdate in the format day month year:");
scanf("%d %d %d",&s[*i].dat.day,&s[*i].dat.month,&s[*i].dat.year);
for (int j=0;j<5;j++)
{
printf("Enter the %dth mark:",j+1);
scanf("%d",&s[*i].mark[j]);
sum+=s[*i].mark[j];
}
s[*i].totalmarks=sum;
printf("Gender(MALE/FEMALE/TRANSGENDER):");
scanf("%s",g);
if(strcmp(g,"MALE")==0)
{
	s[*i].gender=0;
}
else if(strcmp(g,"FEMALE")==0)
{
	s[*i].gender=1;
}
else
{
	s[*i].gender=2;
}
}	

void comrank(student *s,int n,int maxm)
{
int r=1,r1=1;
for (int i=maxm;i>=0;i--)
{
for (int j=0;j<n;j++)
{
if (s[j].totalmarks==i)
{
s[j].rank=r;
r1+=1;
}
}
r=r1;
}
}
void display(student *s,int n)
{
int pos,a=1;
char sname[50];

while(a!=0)
{
pos=-1;
printf("Enter the name of the student whose detais you want:");
scanf("%s",sname);

for (int i=0;i<n;i++)
{
if(strcmp(s[i].name,sname)==0)
{
pos=i;
break;
}
}

if(pos==-1)
{
	printf("No such person found!\nTry another name!\n");
	continue;
}

printf("\t\t\t\t%s's Mark Sheet\n",s[pos].name);
printf("Name:%s\n",s[pos].name);
printf("Rollno:%d\n",s[pos].rollno);
printf("Age:%d\n",s[pos].age);
printf("Date of Birth:%d:%d:%d\n",s[pos].dat.day,s[pos].dat.month,s[pos].dat.year);

if (s[pos].gender==0)
{
printf("Gender:Male\n");
}
else if(s[pos].gender==1)
{
printf("Gender:Female\n");
}
else
{
printf("Gender:Transgender\n");
}

for (int j=0;j<5;j++)
{
printf("Marks of %dth subject:%d\n",j+1,s[pos].mark[j]);
}
printf("Totalmark:%d\n",s[pos].totalmarks);
printf("Rank:%d\n",s[pos].rank);
printf("Press 1 to get the marksheet of other students or Press 0 to exit:");
scanf("%d",&a);
}
}
