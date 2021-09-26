

typedef struct mystack
{
	char data;
	struct mystack *next;
}stack;

stack* push(char ele,stack *top);
char pop(stack** top);

stack* push(char ele,stack *top)
{
	stack *new;
	new=(stack *)malloc(sizeof(stack));
	new->data=ele;
	new->next=top;
	top=new;
	return top;
}
char pop(stack** top)
{
	char temp;
	stack *new;
	new=(stack *)malloc(sizeof(stack));
	new=(*top);
	temp=new->data;
	(*top)=(*top)->next;
	free(new);
	return temp;
}
