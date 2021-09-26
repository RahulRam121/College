#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"functions.h"
#include"prototype.h"

int main()
{
	int s,ch;
	node *head,*tail;
	head=(node *)malloc(sizeof(node));
	tail=(node *)malloc(sizeof(node));
	head->next=tail;
	head->prev=NULL;
	tail->next=NULL;
	tail->prev=head;
	printf("Press\n1.Insert First.\n2.Insert Last.\n3.Insert after a name.\n4.Search a student's name.\n5.Delete a student name.\n6.Display all name.\n7.Display all names in alphabetical order.\n8.Exit.\n");
	scanf("%d",&ch);
	while(ch!=8)
	{
		switch(ch)
		{
			case 1:insertfirst(head);printf("Inserted Successfully!\n");break;
			case 2:insertlast(head);printf("Inserted Successfully!\n");break;
			case 3:insertmiddle(head);break;
			case 4:printf("Search a name!\n");s=search(head);
			if(s!=-1)
			{
				printf("Name found in %dth position.\n",s);
			}
			break;
			case 5:delete(head);break;
			case 6:display(head);break;
			case 7:displaya(head);display(head);break;
			case 8:return 0;
			default:printf("Invalid Input!\n");
		}
		printf("Press\n1.Insert First.\n2.Insert Last.\n3.Insert after a name.\n4.Search a student's name.\n5.Delete a student name.\n6.Display all name.\n7.Display all names in alphabetical order.\n8.Exit.\n");
		scanf("%d",&ch);
	}
	return 0;
}
