#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"avl.h"

int main()
{
	int ch,ch1=1;
	char eng[25],tam[25],hindi[25];
	avl *tree=NULL;
	printf("Menu\n1.Enter the words.\n2.Search a word.\n3.Exit.\nEnter your choice:");
	scanf("%d",&ch);
	while(ch!=3)
	{
		switch(ch)
		{
			case 1:
			{
				ch1=1;
				while(ch1==1)
				{
					printf("Enter the english word:");
					scanf("%s",eng);
					printf("Enter its tamil word:");
					scanf("%s",tam);
					printf("Enter its hindi word:");
					scanf("%s",hindi);
					tree=insert(eng,tam,hindi,tree);
					printf("Inserted Successfully!\n");
					printf("\n");
					printf("Displaying elemens in the dictionary in alphabetical order!\n");
					inorderdisplay(tree);
					printf("\n");
					printf("Continue(1.Yes/2.No):");
					scanf("%d",&ch1);
				}
				break;
			}
			case 2:
			{
				printf("Enter the english word:");
				scanf("%s",eng);
				searchnprint(eng,tree);
				break;
			}
			default:printf("Invalid Input!\n");
		}
		printf("\n");
		printf("Menu\n1.Enter the words.\n2.Search a word.\n3.Exit.\nEnter your choice:");
		scanf("%d",&ch);
		printf("\n");
	}
	return 0;
}

