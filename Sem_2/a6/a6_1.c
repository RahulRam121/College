#include<stdio.h>
#include<string.h>

struct name
{
char cname[40];
char ename[40];
char wname[40];
};

struct grosspay
{
float BP,DA,HRA,CCA;
};

struct dedu
{
float INS,PF;
};

struct payslip
{
struct name sname;
struct grosspay gp;
struct dedu sdedu;
float netpay;
};

int main()
{

struct payslip spay;
getdata(&spay);
calc(&spay);
display(&spay);
return 0;
}


void display(struct payslip *spay)
{
printf("            Name of the Company:%s\n",spay->sname.cname);
printf("Name of the employer:%s\n",spay->sname.ename);
printf("Name of the employee:%s\n",spay->sname.wname);
printf("                          Income details:\n");
printf("BP:%.2f\n",spay->gp.BP);
printf("DA:%.2f\n",spay->gp.DA);
printf("HRA:%.2f\n",spay->gp.HRA);
printf("CCA:%.2f\n",spay->gp.CCA);
printf("                        Deduction Details:\n");
printf("Insurance:%.2f\n",spay->sdedu.INS);
printf("PF:%.2f\n",spay->sdedu.PF);
printf("\t\t\tNETPAY:Rs%.2lf\n",spay->netpay);

}

void getdata(struct payslip *spay)
{
printf("Enter the name of the company: ");
scanf("%s",spay->sname.cname);
printf("Enter the name of the employer: ");
scanf("%s",spay->sname.ename);
printf("Enter the name of the employee: ");
scanf("%s",spay->sname.wname);
printf("Enter Basic Pay: ");
scanf("%f",&spay->gp.BP);
}

void calc(struct payslip *spay)
{
float total,dedu;
spay->gp.DA=0.88*spay->gp.BP;
spay->gp.HRA=0.08*spay->gp.BP;
spay->gp.CCA=1000;
spay->sdedu.INS=2000;
spay->sdedu.PF=0.10*spay->gp.BP;
total=spay->gp.BP+spay->gp.DA+spay->gp.HRA+spay->gp.CCA;
dedu=spay->sdedu.INS+spay->sdedu.PF;
spay->netpay=total-dedu;
}
