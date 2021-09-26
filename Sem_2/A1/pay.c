#include<stdio.h>
int main()
{
int bp,emp_id;
float da,hra,cca,insurance,pf,gross,dedu,net_pay;
char name[20];
printf("enter ur name:");
scanf("%s",name);
printf("enter the employee id:");
scanf("%d",&emp_id);
printf("enter bp:");
scanf("%d",&bp);
da=0.88*bp;
hra=0.08*bp;
cca=1000;
insurance=2000;
pf=0.12*bp;
gross=bp+da+hra+cca;
dedu=insurance+pf;
net_pay=gross-dedu;
printf("name%7c%s",':',name);
printf("\nEmployeeid:%d",emp_id);
printf("\nBP%9c%d",':',bp);
printf("\nDA%9c%f",':',da);
printf("\nHRA%8c%f",':',hra);
printf("\nCCA%8c%f",':',cca);
printf("\nInsurance%2c%f",':',insurance);
printf("\nGross_Pay%2c%f",':',gross);
printf("\nDeduction%2c%f",':',dedu);
printf("\n");
printf("%10cNet_Pay:%f",' ',net_pay);
printf("\n");
return 0;
}
