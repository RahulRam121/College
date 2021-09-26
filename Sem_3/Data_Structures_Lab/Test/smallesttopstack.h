typedef struct mystack
{
	int value;
	struct mystack *next;
}stack;
struct mystack *top=NULL;

stack* createStack();
void push(int item);
int pop();
void display();

stack* createStack()
{
	int num,ch=1,temp,n=0;
	int arr[100];
	while(ch==1)
	{
		printf("Enter the number:");
		scanf("%d",&num);
		if(top==NULL)
		{
			push(num);
		}
		else
		{
			if(num>top->value)
			{
				temp=pop();
				arr[n]=temp;		
				while(top!=NULL)
				{
					if(num>top->value)
					{
						temp=pop();
						n++;
						arr[n]=temp;
					}
					else
					{
						break;
					}
				}
				push(num);
				while(n>=0)
				{
					push(arr[n]);
					n-=1;
				}
				n+=1;
			}
			else
			{
				push(num);
			}
		
		}printf("Stack's current order :");
		display();
		printf("\n");
		printf("Continue(1.Yes/2.No)");
		scanf("%d",&ch);
	}
	return top;
}

void push(int item)
{
	stack *new;
	new=(stack *)malloc(sizeof(stack));
	new->value=item;
	new->next=top;
	top=new;
}

int pop()
{
	int no;
	stack *temp;
	no=top->value;
	temp=(stack *)malloc(sizeof(stack));
	temp=top;
	top=top->next;
	free(temp);
	return no;
}

void display()
{
	stack *temp=top;
	while(temp!=NULL)
	{
		printf("%d ",temp->value);
		temp=temp->next;
	}
}
