#include<stdio.h>
int main()
{
float cel,far,kel;
printf("Enter celcius value ");
scanf("%f",&cel);
far=(cel*9)/5+32;
kel=cel+273;
printf("The farenhiet is %f \n",far);
printf("The kelvin is %f \n",kel);
return 0;
}

