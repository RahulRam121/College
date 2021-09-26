#include<stdio.h>
int main()
{
float a,b;
char op;
printf("Enter a number,operator,another number: ");
scanf("%f %c %f",&a,&op,&b);
switch(op)
{
	case'+':
		printf("Sum=%f\n",a+b);
		break;
	case'-':
		printf("Difference=%f\n",a-b);
		break;
	case'*':
		printf("product=%f\n",a*b);
		break;
	case'/':
		printf("Quotient=%f\n",a/b);
		break;
	case'^':
		printf("Exponentiation=%f\n",a*a);
		break;
	default:
		printf("Operator is invalid");
}
return 0;
}
	
