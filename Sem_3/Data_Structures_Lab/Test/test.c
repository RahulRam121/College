#include<stdio.h>
#include<stdlib.h>

#include"smallesttopstack.h"

int main()
{
	stack *c;
	c=createStack();
	printf("Required order :");
	display();
	return 0;
}
