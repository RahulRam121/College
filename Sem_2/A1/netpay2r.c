#include<stdio.h>
void main()
{
	float bp,da,hra,cca,ins,pf,gp,dedu,netpay;
	char opthra,optcca;
	printf("Enter the basic pay amount:");
	scanf("%f",&bp);
	printf("enter the option as m or c or t:");
	scanf(" %c",&opthra);
	switch(opthra)
	{	
		case 'm':hra=0.1*bp;break;
		case 'c':hra=0.08*bp;break;
		default:hra=0.05*bp;
	}
	printf("\n");
	printf("enter the option as w or e or m:");
	scanf(" %c",&optcca);
	switch(optcca)
	{
		case 'w':cca=1000;break;
		case 'e':cca=2000;break;
		default:cca=5000;
	}
	da=0.88*bp;
	pf=0.1*bp;
	ins=1000;
	gp=bp+da+hra+cca;
	dedu=ins+pf;
	netpay=gp-dedu;
	printf("DA:%f",da);
	printf("\n");
	printf("PF:%f",pf);
	printf("\n");
	printf("Gross_Pay:%f",gp);
	printf("\n");
	printf("Deduction:%f",dedu);
	printf("\n");
	printf("Net_Pay:%f",netpay);
	printf("\n");
}
