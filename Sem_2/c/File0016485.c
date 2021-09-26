#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
double table(double(*pf)(double i,int m,double n),double a,int m,double n,int j);
double md1(double i, int m,double n);
double md2(double i, int m,double n);
double md3(double i, int m,double n);
void display(double *a[15],double *b[15],double *c[15],double *d[15],double *e[15],double *f[15],int x);
int main()
{
int m;
double n,a,A[20],S[20],Q[20],M[20],D[20],C[20];
printf("FUTURE VALUE OF A SERIES OF MONTHLY DEPOSITS\n");
printf("Amount of each monthly payment: ");
scanf("%lf", &a);
printf("Number of years:");
scanf("%lf", &n);
printf("\t\tA=%.2lf\n",a);
printf("\t\tn=%.2lf\n",n);
printf("Interest\tAnnual\t\tSemiannual\tQuarterly\tMonthly\t\tDaily\t\tContinuous\n");
printf("Rate\t\tCompounding\tCompounding\tCompounding\tCompounding\tCompounding\tCompounding\n");

for (int j=0;j<11;j++)
{
	m=1;
	A[j]=table(md1,a,m,n,j);
	m=2;
	S[j]=table(md1,a,m,n,j);
	m=4;
	Q[j]=table(md1,a,m,n,j);
	m=6;
	M[j]=table(md1,a,m,n,j);
	m=360;
	D[j]=table(md2,a,m,n,j);
	m=0;
	C[j]=table(md3,a,m,n,j);
}


for(int k=0;k<11;k++)
{
	printf("%d%%\t\t",k+5);
	display(&A,&S,&Q,&M,&D,&C,k);
	printf("\n");	
}
return 0;
}
double table(double(*pf)(double i,int m,double n),double a,int m,double n,int j)
{
	double i,f;
	i=0.01*(j+5);
	f=a*(*pf)(i,m,n);
	return f;
}		
double md1(double i,int m,double n)
{
double factor,ratio;
factor=1+i/m;
ratio=12*(pow(factor,m*n)-1)/i;
return(ratio);
}
double md2(double i,int m,double n)
{
double factor,ratio;
factor=1+i/m;
ratio=(pow(factor,m*n)-1)/ (pow(factor,m/12)-1);
return (ratio);
}
double md3(double i,int m,double n)
{
double ratio;
ratio=(exp(i*n)-1)/(exp(i/12)-1);
return(ratio);
}
void display(double *a[15],double *b[15],double *c[15],double *d[15],double *e[15],double *f[15],int x)
{
	printf("%.2lf\t\t%.2lf\t\t%.2lf\t\t%.2lf\t\t%.2lf\t\t%.2lf\t\t",*(a+x),*(b+x),*(c+x),*(d+x),*(e+x),*(f+x));

}
