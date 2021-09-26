typedef struct mystack
{
	char data;
	struct mystack *next;
}stack;

int testexp(char exp[]);
stack* push(char ele,stack *top);
char pop(stack** top);
int ismatching(char c1,char c2);
char *postfix(char exp[]);

int testexp(char exp[])
{
	stack *top;
	top=NULL;
	int i=0,s=1;
	while(exp[i])
	{
		if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
		{
			top=push(exp[i],top);
		}
		
		else if(exp[i]=='}'||exp[i]==')'||exp[i]==']')
		{
			if(top!=NULL)
			{
				s=ismatching(pop(&top),exp[i]);
			}
			else
			{
				return 0;
			}
			if(s==0)
			{
				return 0;
			}
		}
		i++;
	}
	if(top==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

char *postfix(char exp[])
{
	stack *top1;
	top1=NULL;
	char c;
	char *nexp=malloc(sizeof(char)*50);
	int i=0,n=0;
	while(exp[i])
	{
		if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
		{
			top1=push(exp[i],top1);
		}
		else if(exp[i]=='+'||exp[i]=='-')
		{
			if(top1!=NULL)
			{
				if((top1->data)=='+'|| (top1->data)=='-' ||(top1->data)=='*' ||(top1->data)=='/')
				{
					c=pop(&top1);
					nexp[n]=c;
					n++;
					nexp[n]='\0';
					top1=push(exp[i],top1);
				}
				else
				{
					top1=push(exp[i],top1);
				}
			}
			else
			{
				top1=push(exp[i],top1);
			}
		}
		else if(exp[i]=='*' || exp[i]== '/')
		{
			if(top1!=NULL)
			{
				if(top1->data=='*' || top1->data=='/')
				{
					c=pop(&top1);
					nexp[n]=c;
					n++;
					nexp[n]='\0';
					top1=push(exp[i],top1);
				}
				else
				{
					top1=push(exp[i],top1);
				}
			}
			else
			{
				top1=push(exp[i],top1);
			}
		}
		else if(exp[i]=='}'||exp[i]==')'||exp[i]==']')
		{
			c=pop(&top1);
			nexp[n]=c;
			n++;
			nexp[n]='\0';
			c=pop(&top1);
			while(c!='{' && c!='(' && c!='[')
			{
				nexp[n]=c;
				n++;
				nexp[n]='\0';
				c=pop(&top1);
			}
		}
		else
		{
			nexp[n]=exp[i];
			n++;
			nexp[n]='\0';
		}
		i++;
	}
	while(top1!=NULL)
	{
		c=pop(&top1);
		nexp[n]=c;
		n++;
		nexp[n]='\0';
	}
	return nexp;
}

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

int ismatching(char c1,char c2)
{
	if(c1=='{'&&c2=='}')
		return 1;
	else if(c1=='('&&c2==')')
		return 1;
	else if(c1=='['&&c2==']')
		return 1;
	else
		return 0;
}
