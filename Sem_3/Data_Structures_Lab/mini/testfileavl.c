#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct busnames
{
	char bus_name[15],bus_no[6],driver_name[15],mob_no[10];
	char ac,seat;
	int sleeper,semi_sleeper,ratings;
	struct busnames *left,*right;
	int height;
}avl;
void inorderdisplay(avl *t);
void inorderdisplay(avl *t)
{
	if(t!=NULL)
	{
		inorderdisplay(t->left);
		printf("Bus Name :%s \nAC : %c\nRatings : %d\n",t->bus_name,t->ac,t->ratings);
		inorderdisplay(t->right);
	}
}
int main()
{
	avl *tree;
	FILE *busfile;
	busfile=fopen("bus.dat","r");
	fread(&tree,sizeof(avl),1,busfile);
	inorderdisplay(tree);
	fclose(busfile);
	
	return 0;
}
