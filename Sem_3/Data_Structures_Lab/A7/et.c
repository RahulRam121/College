#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"CharStack.h"
#include"TestStack.h"

int main()
{
	int ch=1,t;
	char exp[50],postexp[50];
	while(ch==1)
	{
		t=1;
	printf("Enter the infix expression:");
	scanf("%s",exp);
	t=testexp(exp);
	if(t==0)
	{
		printf("Unbalanced expression!\n");
	}
	else
	{
		printf("Balanced expression!\n");
	strcpy(postexp,postfix(exp));
	int j=0;
	printf("Required postfix expression!\n");
	while(postexp[j]!='\0')
	{
		printf("%c" ,postexp[j]);
		j++;
	}
	printf("\n");
	et* t = constructTree(postexp);
	printf("Preorder : ");
	preorder(t);
	printf("\nInorder  : ");
	inorder(t);
	printf("\nPostorder: ");
	postorder(t);
	printf("\n");
	}
	printf("Continue(1.Yes 2.No):");
	scanf("%d",&ch);
	}
	return 0;
}
