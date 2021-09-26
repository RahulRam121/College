#include<stdio.h>
#include<stdlib.h>
typedef struct mynode
{
	int data;
	struct mynode *next;
}node;

node* CreateEmptyList()
{
	node *h;
	h=(node*)malloc(sizeof(node));
	h->next=NULL;
	return h;
}

void InsertFirst(node *hd,int element)
{
	node *p;
	p=(node*) malloc(sizeof(node));
	p->data=element;
	p->next=hd->next;
	hd->next=p;
}
int main()
{
	node *head;
	node *p;
	head=CreateEmptyList();
	int ele;
	printf("Enter the element:");
	scanf("%d",&ele);
	InsertFirst(head,ele);
	p=head->next;
	printf("%d",p->data);
	return 0;
}
