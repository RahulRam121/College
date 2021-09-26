

typedef struct mystack
{
	int data;
	struct mystack *next;
}stack;

stack* push(int ele,stack *top);
int pop(stack** top);

stack* push(int ele,stack *top)
{
	stack *new;
	new=(stack *)malloc(sizeof(stack));
	new->data=ele;
	new->next=top;
	top=new;
	return top;
}
int pop(stack** top)
{
	int temp;
	stack *new;
	new=(stack *)malloc(sizeof(stack));
	new=(*top);
	temp=new->data;
	(*top)=(*top)->next;
	free(new);
	return temp;
}
