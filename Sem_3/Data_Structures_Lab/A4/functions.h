typedef struct studentlist
{
	char name[20];
	struct studentlist *prev,*next;
}node;

void insertfirst(node *hd)
{
	node *temp;
	temp=(node *)malloc(sizeof(node));
	printf("Enter the student's name:");
	scanf("%s",temp->name);
	temp->next=hd->next;
	temp->prev=hd;
	hd->next->prev=temp;
	hd->next=temp;
}

void insertlast(node *hd)
{
	node *p,*tl,*temp;
	temp=(node *)malloc(sizeof(node));
	for(p=hd->next;p->next!=NULL;p=p->next)
	{
			tl=p->next;
	}
	printf("Enter the student's name:");
	scanf("%s",temp->name);
	temp->next=tl;
	temp->prev=tl->prev;
	tl->prev->next=temp;
	tl->prev=temp;
}

void insertmiddle(node *hd)
{
	node *mid,*temp;
	int s;
	s=search(hd);
	if(s==-1)
	{
		return;
	}
	mid=hd->next;
	for(int i=0;i<s;i++)
	{
		mid=mid->next;
	}
	temp=(node *)malloc(sizeof(node));
	printf("Enter the student's name:");
	scanf("%s",temp->name);
	temp->next=mid;
	temp->prev=mid->prev;
	mid->prev->next=temp;
	mid->prev=temp;
	printf("Inserted Successfully!\n");
}

void delete(node *hd)
{
	printf("Enter the student's name you want to delete!\n");
	int d=search(hd);
	if(d==-1)
	{
		return;
	}
	node *del,*temp;
	del=hd->next;
	for(int i=0;i<(d-1);i++)
	{
		del=del->next;
	}
	temp=del;
	del->next->prev=del->prev;
	del->prev->next=del->next;
	free(temp);
	printf("Deleted Successfully!\n");
}

int search(node *hd)
{
	node *s;
	int count=0,c=0;
	char sname[20];
	printf("Enter the name:");
	scanf("%s",sname);
	for(s=hd->next;s!=NULL;s=s->next)
	{
		c++;
	}
	for(s=hd->next;s->next!=NULL;s=s->next)
	{
		if(strcmp(s->name,sname)==0)
		{
			break;
		}
		else
		{
			count++;
		}
	}
	if((count+1)==c)
	{
		printf("Name not FOUND!\n");
		return -1;
	}
	else
	{
		return count+1;
	}
}

void display(node *hd)
{
	node *p;
	for(p=hd->next;p->next!=NULL;p=p->next)
	{
		printf("%s",p->name);
		printf("\n");
	}
}

void displaya(node *hd)
{
	node *p,*q;
	int c=0;
	char n[20];
	for(p=hd->next;p!=NULL;p=p->next)
	{
		c++;
	}
	for(int i=0;i<(c-1);i++)
	{
		for(p=hd->next;p->next->next!=NULL;p=p->next)
		{
			for(q=p->next;q->next!=NULL;q=q->next)
			{
				if(strcmp(p->name,q->name)>0)
				{
					strcpy(n,p->name);
					strcpy(p->name,q->name);
					strcpy(q->name,n);
				}
			}
		}
	}
	printf("Displaying the names in the alphabetical order!\n");
}
