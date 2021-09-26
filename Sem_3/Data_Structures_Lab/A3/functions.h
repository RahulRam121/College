typedef struct mynode
{
	int coeff,pow;
	struct mynode *next;
}node;

node*  CreateList()
{
	node *head,*new;
	int ch;
	head=(node *)malloc(sizeof(node));
	new=(node *)malloc(sizeof(node));
	head->next=NULL;
	printf("Enter the coeff : ");
	scanf("%d",&new->coeff);
	printf("Enter its power: ");
	scanf("%d",&new->pow);
	new->next=NULL;
	head->next=new;
	printf("Continue(1.yes/2.no):");
	scanf("%d",&ch);
	while(ch==1)
	{	
		node *temp;
		temp=(node *)malloc(sizeof(node));
		printf("Enter the coeff : ");
		scanf("%d",&temp->coeff);
		printf("Enter its power: ");
		scanf("%d",&temp->pow);
		temp->next=NULL;
		new->next=temp;
		new=temp;
		printf("Continue(1.yes/2.no):");
		scanf("%d",&ch);
	}
	return head;
}

void display(node *a,int l)
{
	node *d;
	if(a->next==NULL)
	{
		printf("-List is empty!\n");
	}
	for(int i=l;i>=0;i--)
	{
		for(d=a->next;d!=NULL;d=d->next)
		{
			if(d->pow==i)
			{
				if(d->coeff>0)
				{
					printf("+");
				}
			printf("%dx^%d ",d->coeff,d->pow);
			}
		}
	}
	printf("\n");
}

node* add(node *a,node *b,int l)
{
	int s1=0,s2=0,t1;
	node *p,*q,*r,*new,*temp;
	r=(node *)malloc(sizeof(node));
	r->next=NULL;
	temp=r;
	
	for(p=a->next;p!=NULL;p=p->next)
	{
		if(p->pow>l)
		{
			l=p->pow;
		}
	}
	for(q=b->next;q!=NULL;q=q->next)
	{
		if(q->pow>l)
		{
			l=q->pow;
		}
	}
	for(int i=l;i >= 0;i--)
	{
		for(p=a->next;p!=NULL;p=p->next)
		{
			s1=0;
			if(p->pow==i)
			{
				s1=1;
				for(q=b->next;q!=NULL;q=q->next)
				{
					s2=0;
					if(q->pow==i)
					{
						s2=1;
						t1=p->coeff+q->coeff;
						if(t1==0)
						{
							break;
						}
						else
						{
							new=(node *)malloc(sizeof(node));
							new->coeff=p->coeff+q->coeff;
							new->pow=i;
							new->next=NULL;
							temp->next=new;
							temp=new;
							break;
						}
					}
				}
				if(s2==0)
				{
					new=(node *)malloc(sizeof(node));
					new->coeff=p->coeff;
					new->pow=i;
					new->next=NULL;
					temp->next=new;
					temp=new;
					break;
				}
				break;
			}
		}
		if(s1==0)
		{
			for(q=b->next;q!=NULL;q=q->next)
			{
				if(q->pow==i)
				{
					new=(node *)malloc(sizeof(node));
					new->coeff=q->coeff;
					new->pow=i;
					new->next=NULL;
					temp->next=new;
					temp=new;
					break;
				}
			}
		}
	}
	return r;
}

node* multiply(node *a,node *b)
{
	node *r,*x,*y,*new,*temp;
	int t,t1=0,t2=0;
	r=(node *)malloc(sizeof(node));
	r->next=NULL;
	temp=r;
	for(x=a->next;x!=NULL;x=x->next)
	{
		for(y=b->next;y!=NULL;y=y->next)
		{
			new=(node *)malloc(sizeof(node));
			new->coeff=x->coeff*y->coeff;
			new->pow=x->pow+y->pow;
			new->next=NULL;
			temp->next=new;
			temp=new;
		}
	}
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
	for(int i=0;i<t;i++)
	{
	
	for(x=r->next;x->next!=NULL;x=x->next)
	{
		for(y=x->next;y!=NULL;y=y->next)
		{	
			if(x->pow==y->pow)
			{
				x->coeff=x->coeff+y->coeff;
				if(y->next!=NULL)
				{
					x->next=x->next->next;
				}
				else
				{
					x->next=NULL;
				}
			}
			
		}
	}
}
	return r;
}

