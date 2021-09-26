#include<stdio.h>
void 
main()
{
int a[10],b[10],user=0,cpu=0,draw=0;
printf("Choose 1 for Rock\n"
	"Choose 2 for Paper\n"
	"Choose 3 for Scissor\n");
for (int i=0;i<10;i++)
{
printf("Enter the %dth choice:",i+1);
scanf("%d",&a[i]);
}
srand(time(0));
for (int i=0;i<10;i++)
{
b[i]=(rand()%3)+1;
}

for (int i=0;i<10;i++)
{
switch(a[i])
{
	case '1':
		if (b[i]==2)
		{
			cpu+=1;
		}
		else if(b[i]==1)
		{
			draw+=1;
		}
		else
		{
			user+=1;
		}
	case '2':
		if (b[i]==2)
		{
			draw+=1;
		}
		else if(b[i]==1)
		{
			user+=1;			
		}
		else
		{
			cpu+=1;
		}
	default:
		if (b[i]==3)
		{
			draw+=1;
		}
		else if(b[i]==2)
		{
			user+=1;
		}
		else
		{
			cpu+=1;
		}
}
}	
printf("Your score:%d""\n",user);
printf("CPU's score:%d""\n",cpu);
printf("No of draws:%d""\n",draw);
if(user>cpu)
{
	printf("You win");
}
else if(user==cpu)
{
	printf("Its a Tie");
}
else
{
	printf("CPU Wins");
}
printf("\n");
}




