#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"binarytree.h"

int main()
{
	int ch=1;
	char sname[25];
	bst *head,*t;
	printf("Press\n1.Insert name to the tree.\n2.Find the Grandparent.\n3.Find the Grandchild.\n4.Find the Siblings.\n5.Delete a name.\n6.Display the tree.\n7.Exit.\nEnter Choice:");
	scanf("%d",&ch);
	while(ch!=7)
	{
		switch(ch)
		{
			case 1:
				{
					head = createtree();
					printf("Displaying tree in inorder transversal..\n");
					display(head);
					break;
				}
			case 2:
				{
					printf("Enter the name of the grandchild:");
					scanf("%s",sname);
					t=findGP(sname,head);
					if(t!=NULL)
						printf("%s is the GrandParent\n",t->name);
					else
						printf("%s has no GrandParent\n",sname);
					break;
				}
			case 3:
				{
					printf("Enter the name of the grandparent:");
					scanf("%s",sname);
					t=findPos(sname,head);					
					if(t!=NULL)
					{
						printf("GrandChildrens : ");
						findGC(t);
						printf("\n");
					}
					else
					{	
						printf("Name not Found!\n");
					}
					break;
				}
			case 4:
				{
					printf("Enter the name of the Sibling:");
					scanf("%s",sname);
					t=findSiblings(sname,head);
				if(t!=NULL)
				{
					printf("\nSibling of %s\n",sname);
					if(strcmp(sname,t->right->name)==0)
						printf("%s\n",t->left->name);
					else if(strcmp(sname,t->left->name)==0)
						printf("%s\n",t->right->name);
					else
						printf("%s has no sibling\n",sname);
				}
				else
					printf("%s is not found\n",sname);
					break;			
				}
			case 5:
				{
					printf("Enter the name to be deleted:");
					scanf("%s",sname);
					head=deleteNode(sname,head);
					break;
				}
			case 6:
				{
					printf("Displaying tree in inorder transversal..\n");
					display(head);
					break;
				}
			default:printf("Invalid Input!\n");
		}
		printf("Press\n1.Insert name to the tree.\n2.Find the Grandparent.\n3.Find the Grandchild.\n4.Find the Siblings.\n5.Delete a name.\n6.Display the tree.\n7.Exit.\nEnter Choice:");
		scanf("%d",&ch);
	}
	return 0;
}


