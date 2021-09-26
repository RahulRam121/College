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



int main()
{
	node *head;
	head=CreateEmptyList();
	return 0;
}
