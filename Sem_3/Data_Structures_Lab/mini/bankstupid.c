#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
	char name[15],acc_no[17];
	int expiry_month,expiry_day,cvv;
	float balance;
}bank;

void printallbank(bank *accs);
void create_bankdetails();

void create_bankdetails(bank *acc)
{
	
	/*char name1[15],name2[17];
	int nums1,nums2,nums3;
	float nums4;*/
	FILE *fp1;
	fp1=fopen("bankacc.dat","wb");	
	for(int i=0;i<3;i++)
	{
		

	printf("Enter the details\n");
	printf("Name :");
	scanf("%s",acc[i].name);
	printf("Account Number :");
	scanf("%s",acc[i].acc_no);
	printf("Expiry Month :");
	scanf("%d",&acc[i].expiry_month);
	printf("Expiry Day :");
	scanf("%d",&acc[i].expiry_day);
	printf("CVV :");
	scanf("%d",&acc[i].cvv);
	printf("Balance :");
	scanf("%f",&acc[i].balance);
	
	}
	fwrite(&acc,sizeof(bank),3,fp1);
	fclose(fp1);
}

void printallbank(bank *accs)
{
	/*for(int i=0;i<3;i++)
	{
		accs[i]=(bank *)malloc(sizeof(bank));
	}*/
	FILE *fp2;
	fp2=fopen("bankacc.dat","rb");
	fread(accs,sizeof(bank),3,fp2);
	fclose(fp2);
	for(int i=0;i<3;i++){
	
		printf("eeeeeeeeeeeeeeeeeeeeeeeeee\n");
		printf("%s %s %.2f\n",accs[i].name,accs[i].acc_no,accs[i].balance);
	
	}
	
}

int main()
{
	bank *ac[10];
	create_bankdetails(&ac);
	printallbank(&ac);
	return 0;
}
