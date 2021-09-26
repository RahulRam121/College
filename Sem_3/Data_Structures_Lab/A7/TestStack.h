typedef struct exptree 
{
	char value;
	struct exptree *left, *right; 
}et;

typedef struct Tree
{
	et *node;
	struct tree *next;
}tree;
tree *top=NULL;

et* constructTree(char postfix[]);
et* newNode(char v);
int isOperator(char c);
et* poptop();
void pushtop(et *t);
void preorder(et* t);
void inorder(et* t);
void postorder(et* t);

int isOperator(char c) 
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') 
		return 1;
	return 0; 
}

et* newNode(char v)
{
	et* temp = (et*)malloc(sizeof(et)); 
	temp->left = temp->right = NULL; 
	temp->value = v;
	return temp;
}

et* poptop()
{
	et *ret=NULL;
	if(top==NULL)
	{
		printf("Stack is Empty!");
	}
	else
	{
		tree *temp=top;
		top=temp->next;
		ret=temp->node;
		free(temp);
	}
	return ret;
}

void pushtop(et *t)
{
	tree *temp=(tree *)malloc(sizeof(tree));
	temp->node=t;
	if(top==NULL)
		temp->next=NULL;
	else
		temp->next=top;
	top=temp;
}

et* constructTree(char postfix[]) 
{
	et *t, *t1, *t2;
	for (int i=0; i<strlen(postfix); i++)
	{	
		if (!isOperator(postfix[i]))
		{
			t = newNode(postfix[i]); 
			pushtop(t);
		}
		else 
		{
			t = newNode(postfix[i]);
			t1 = poptop();
			t2 = poptop();
			t->right = t1;
			t->left = t2;
			pushtop(t);
		}
	}
	t = poptop();
	return t;
}

void preorder(et* t) 
{
	if(t!=NULL)
	{
		printf("%c",t->value); 
		preorder(t->left); 
		preorder(t->right);
	}
}

void inorder(et* t) 
{
	if(t!=NULL)
	{
		inorder(t->left); 
		printf("%c",t->value); 
		inorder(t->right);
	}
}

void postorder(et* t) 
{
	if(t!=NULL)
	{
		postorder(t->left); 
		postorder(t->right); 
		printf("%c",t->value); 
	}
}
