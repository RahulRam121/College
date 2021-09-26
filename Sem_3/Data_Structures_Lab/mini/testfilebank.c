#include <stdio.h>
struct bankaccount
{
   char name[50],acc_no[17];
   int expiry_month,expiry_day,cvv;
   float balance;
};
int main(){
    struct bankaccount bank1[5], bank2[5];   
    int i;
    FILE *fptr;    
    /*fptr = fopen("file.txt","wb");
    for(i = 0; i < 5; ++i)
    {
        fflush(stdin);
        printf("Name: ");
        gets(bank1[i].name);
        printf("Account Number: ");
        gets(bank1[i].acc_no);
        printf("Expiry Month: ");
        scanf("%d", &bank1[i].expiry_month);
        printf("Expiry Day: ");
        scanf("%d", &bank1[i].expiry_day);
        printf("CVV: ");
        scanf("%d", &bank1[i].cvv);
        printf("Balance: "); 
        scanf("%f", &bank1[i].balance); 
    }
    fwrite(bank1, sizeof(bank1), 1, fptr);
    fclose(fptr);*/
    fptr = fopen("file.txt", "rb");
    fread(bank2, sizeof(bank2), 1, fptr);
    for(i = 0; i < 5; ++i)
    {
        //printf("Name: %s\nAccount Number: %s\nExpiry Month: %d\nExpiry Day: %d\nCVV: %d\nBalance: %f", bank2[i].name, bank2[i].acc_no, bank2[i].expiry_month,bank2[i].expiry_day,bank2[i].cvv,bank2[i].balance);
        if(strcmp(bank2[i].acc_no,accno)==0)
        {
        	int sel_acc=i;
		}
    }
    fclose(fptr);
}
