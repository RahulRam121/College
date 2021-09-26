#include<stdio.h>
#include<stdlib.h>

#include"functions.h"
#include"prototype.h"

int main()
{
	node *a,*b,*sum,*mul,*x;
	int l,t,t1=0,t2=0,ch;
	
	printf("Enter the 1st polynomial list:\n");
	a=CreateList();
	printf("Enter the 2nd polynomial list:\n");
	b=CreateList();
	
	for(x=a->next;x!=NULL;x=x->next)
	{
		if(x->pow>l)
		{
			l=x->pow;
		}
	}
	for(x=b->next;x!=NULL;x=x->next)
	{
		if(x->pow>l)
		{
			l=x->pow;
		}
	}
	printf("Displaying 1st polynomial list!\n");
	display(a,l);
	printf("Displaying 2nd polynomial list!\n");
	display(b,l);
	
	printf("Press\n1.Add two polynomial equations.\n2.Multiply two polynomial equation.\n3.Exit.\n");
	printf("Enter your choice:");
	scanf("%d",&ch);
	while(ch!=3)
	{
		switch(ch)
		{
			case 1:sum=add(a,b,l);
				printf("Displaying the sum polynomial list!\n");
				display(sum,l);break;
			case 2:
			{
				mul=multiply(a,b);
				for(x=a->next;x!=NULL;x=x->next)
				{
					if(x->pow>t1)
					{
						t1=x->pow;
					}
				}
				for(x=b->next;x!=NULL;x=x->next)
				{
					if(x->pow>t2)
					{
						t2=x->pow;
					}
				}
				t=t1+t2;
				printf("Displaying the multiply list!\n");
				display(mul,t);
				break;
			}
			case 3:return 0;
			default:printf("Invalid Input!\n");
		}
		printf("Press\n1.Add two polynomial equations.\n2.Multiply two polynomial equation.\n3.Exit.\n");
		printf("Enter your choice:");
		scanf("%d",&ch);	
	}	
}

