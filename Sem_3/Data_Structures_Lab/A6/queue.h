typedef struct myqueue
{
	char jno[4];
	float bt;
	struct myqueue *next;
}queue;

void enqueue(queue **Qf,queue **Qr,char jno[],float bt)
{
	queue *new,*temp;
	new=(queue *)malloc(sizeof(queue));
	strcpy(new->jno,jno);
	new->bt=bt;
	new->next=NULL;
	if((*Qr)==NULL)
	{
		(*Qf)=(*Qr)=new;
	}
	else if((*Qf)->next==NULL)
	{
		temp=(*Qr);
		(*Qr)=new;
		(*Qf)->next=(*Qr);
	}
	else
	{
		(*Qr)->next=new;
		(*Qr)=(*Qr)->next;
	}
}

void display(queue **Qf,float awt)
{
	queue *temp1;
	for(temp1=(*Qf);temp1!=NULL;temp1=temp1->next)
	{
		printf("Job Number:%s\t",temp1->jno);
		printf("Burst Time:%.2f\n",temp1->bt);
	}
	printf("Average waiting time is:%.2f\n\n",awt);
}

