#include<stdio.h>
#include<string.h>
struct mfgdate
{
int mday,mmon,myr;
};
struct expdate
{
int eday,emon,eyr;
};
struct Medicine
{
char name[50],vname[40];
struct mfgdate mdate;
struct expdate edate;
float cost;
int items;
};
int main()
{
void getdata(int *num,struct Medicine *med);
void selldrug(int *num,struct Medicine *med);
void deldrug(int *num,struct Medicine *med);
void checkdata(int *num,struct Medicine *med);
void displaydata(int *num,struct Medicine *med);
void checkwarning(int *num,struct Medicine *med);
int searchdrug(int *n,struct Medicine *med);
struct Medicine med[1000];
int num=0,n;
printf("PRESS\n");
printf("1.Add drug(while buying a new drug) or create drug list.\n2.Sell a drug\n3.Delete a particular drug\n4.Check availability of a drug\n5.Display all the drug in the form of a list\n6.Close the application\n");
scanf("%d",&n);
while(n!=6)
{
switch (n)
{
case 1:getdata(&num,&med);break;
case 2:selldrug(&num,&med);checkwarning(&num,&med);break;
case 3:deldrug(&num,&med);break;
case 4:checkdata(&num,&med);break;
case 5:displaydata(&num,&med);break;
case 6:checkwarning(&num,&med);return 0;
default:printf("Enter a valid input\n");break;
}
printf("1.Add drug(while buying a new drug) or create drug list.\n2.Sell a drug\n3.Delete a particular drug\n4.Check availability of a drug\n5.Display all the drug in the form of a list\n6.Close the application\n");
scanf("%d",&n);
if (n==6)
{
	checkwarning(&num,&med);
}
}
return 0;
}
void getdata(int *num,struct Medicine *med)
{
char ch;
ch ='Y';
while(ch=='Y')
{
*num=*num+1;
printf("Enter the name of the drug:");
scanf("%s",med[*num-1]->name);
printf("Enter the name of the vendor:");
scanf("%s",med[*num-1].vname);
printf("Enter the manufactured date of the drug in the format day month year:");
scanf("%d %d %d",&med[*num-1].mdate.mday,&med[*num-1].mdate.mmon,&med[*num-1].mdate.myr);
printf("Enter the expiry date of the drug in the format day month year:");
scanf("%d %d %d",&med[*num-1].edate.eday,&med[*num-1].edate.emon,&med[*num-1].edate.eyr);
printf("Enter the cost of the drug:");
scanf("%f",&med[*num-1].cost);
printf("Amount of this drug bought:");
scanf("%d",&med[*num-1].items);
printf("Enter Y to continue entering the data, N to stop entering the data:");
scanf(" %c",&ch);
}
printf("DRUGS LIST UPDATED!\n");
}
void selldrug(int *num,struct Medicine *med)
{
int x,y;
x=searchdrug(&(*num),&(*med));
if(x==-1)
{return;}
printf("Enter the amount of drug you sold:");
scanf("%d",&y);
med[x].items=med[x].items-y;
printf("DRUGS LIST UPDATED!\n");
}
void deldrug(int *num,struct Medicine *med)
{
int x,y;
x=searchdrug(&(*num),&(*med));
if(x==-1)
{return;}
for (int i=x;i<(*num-1);i++)
{
int a,b;
a=strlen(med[i+1].name);
for(int j=0;j<a;j++)
{
	med[i].name[j]=med[i+1].name[j];
}
med[i].name[a]='\0';
b=strlen(med[i+1].vname);
for(int j=0;j<a;j++)
{
	med[i].vname[j]=med[i+1].vname[j];
}
med[i].vname[b]='\0';
med[i].mdate.mday=med[i+1].mdate.mday;
med[i].mdate.mmon=med[i+1].mdate.mmon;
med[i].mdate.myr=med[i+1].mdate.myr;
med[i].edate.eday=med[i+1].edate.eday;
med[i].edate.emon=med[i+1].edate.emon;
med[i].edate.eyr=med[i+1].edate.eyr;
med[i].cost=med[i+1].cost;
med[i].items=med[i+1].items;
}
*num=*num-1;
printf("DELETION COMPLETED!\n");
}
void checkdata(int *num,struct Medicine *med)
{
int x,y;
x=searchdrug(&(*num),&(*med));
if(x==-1)
{return;}
y=med[x].items;
printf("AMOUNT OF DRUG IN THE STOCK IS: %d\n",y);
}
void displaydata(int *num,struct Medicine *med)
{
int a1,a2;
printf("\t\t\t\tDRUG LIST\n");
printf("S/No\tName of drug\t\tVendor name\t\tManufactured date\tExpiry date\tCost\tStock\n");
for(int i=0;i<*num;i++)
{
a1=20-strlen(med[i].name);
a2=18-strlen(med[i].vname);
printf("%d\t",i+1);
printf("%s\t\t%s\t\t%d:%d:%d\t\t\t%d:%d:%d\t%.2f\t%d\n",med[i].name,med[i].vname,med[i].mdate.mday,med[i].mdate.mmon,med[i].mdate.myr,med[i].edate.eday,med[i].edate.emon,med[i].edate.eyr,med[i].cost,med[i].items);
}
}
void checkwarning(int *n,struct Medicine *med)
{
int x=0;
for(int i=0;i<*n;i++)
{
if ((med[i].items)<10)
{
printf("AVAILABILITY OF %s DRUG IS LESS THAN 10.BUY NOW!!\n",med[i].name);
x=1;
}
}
if (x==0)
{ 
printf("EVERY DRUG STOCK IS ABOVE 10.GOOD WORK!!\n");
}
}
int searchdrug(int *n,struct Medicine *med)
{
int x=0,y;
char srch[50];
printf("Enter the name of the drug you want to search:");
scanf("%s",srch);
for (int i=0;i<(*n);i++)
{
if (strcmp(srch,med[i].name) == 0)
{
y=i;
x=1;
}
}
if (x==0)
{
printf("The given drug is not found in the list!\n");
y=-1;
}
return y;
}
	
