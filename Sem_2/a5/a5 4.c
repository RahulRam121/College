#include<stdio.h>
void readinput(int *pm,int *pd,int *py);
int ndays(int mm,int dd,int yy);
int main()
{
int mm1,dd1,yy1,mm2,dd2,yy2,days1,days2;;
printf("Enter the month date year of the first date:");
readinput(&mm1,&dd1,&yy1);
printf("Enter the month date year of the second date:");
readinput(&mm2,&dd2,&yy2);
days1=ndays(mm1,dd1,yy1);
days2=ndays(mm2,dd2,yy2);
if (days1-days2 >= 0)
{
printf("The difference between the two dates is:%d\n",days1-days2);
}
else
{
printf("The differnce between the two dates is:%d\n",days2-days1);
}
return 0;
}
void readinput(int *pm,int *pd,int *py)
{
scanf("%d %d %d",pm,pd,py);
return;
}
int ndays(int mm,int dd,int yy)
{
int nyears,nodays;
long ndays,ncycles;
yy-=1900;
ndays=(long)(30.42 * (mm-1) + dd);
if(mm==2) ++ndays;
if ((mm>2) && (mm<8)) --ndays;
if ((yy%4==0) && (mm>2)) ++ndays;
ncycles=yy/4;
ndays+=ncycles*1461;
nyears=yy % 4;
if (nyears>0)
{
	ndays+=365*nyears+1;
}
if (ndays>59) --ndays;
nodays=ndays;
return nodays;
} 
