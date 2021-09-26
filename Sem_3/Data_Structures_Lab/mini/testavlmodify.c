#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct mytree
{
	char eng[25],tam[25],hindi[25];
	struct mytree *left,*right;
	int height;
}avl;

static int findheight(avl *tree);
avl* insert(char eng[],char tam[],char hindi[], avl *t);
int max(int a,int b);
static avl* singlerotatewithleft(avl *k2);
static avl* singlerotatewithright(avl *k2);
static avl* doublerotatewithleft(avl *k3);
static avl* doublerotatewithright(avl *k3);
avl* searchnprint(char eng[],avl *t);
void inorderdisplay(avl *t);

static int findheight(avl *tree)
{
	if(tree==NULL)
		return -1;
	else
		return tree->height;
}

avl* insert(char eng[],char tam[],char hindi[], avl *t) 
{
	if(t==NULL)
	{
		t=(avl *)malloc(sizeof(avl)); 
		if(t==NULL)
		{
			printf("Out of Space\n"); 
		}
		else
		{
			strcpy(t->eng,eng); 
			strcpy(t->tam,tam);
			strcpy(t->hindi,hindi);
			t->height=0; 
			t->left=t->right=NULL;
		}
	}
	else if(strcmp(eng,t->eng) < 0)
	{
		t->left=insert(eng,tam,hindi,t->left);
		if(findheight(t->left) - findheight(t->right) == 2)
		{
			if(strcmp(eng,t->left->eng) < 0)
			{			
				printf("Rotations:Single rotation with left!\n");
				t=singlerotatewithleft(t);				
			}
			else
			{			 
				printf("Rotations:Double rotation with left!\n");
				t=doublerotatewithleft(t);				
			}
		}
	}
	else if(strcmp(eng,t->eng) > 0)
	{
		t->right=insert(eng,tam,hindi,t->right); 	
		if(findheight(t->left) - findheight(t->right) == 2)
		{
			if(strcmp(eng,t->right->eng) > 0)
			{			
				printf("Rotations:Single rotation with right!\n");
				t=singlerotatewithright(t);				
			}			
			else
			{		  
				printf("Rotations:Double rotation with right!\n");
				t=doublerotatewithright(t);
			}
		}
	} 
	t->height=max(findheight(t->left),findheight(t->right))+1; 
	return t;
}

int max(int a,int b)
{
	return (a>b)?a:b;
}

static avl* singlerotatewithleft(avl *k2) 
{
	avl *k1;
	k1=k2->left;
	k2->left=k1->right;
	k1->right=k2; 
	k2->height=max(findheight(k2->left),findheight(k2->right))+1; 
	k1->height=max(findheight(k1->left),k2->height)+1;
	return k1; 
}

static avl* singlerotatewithright(avl *k2) 
{
	avl *k1;
	k1=k2->right;
	k2->right=k1->left;
	k1->left=k2; 
	k2->height=max(findheight(k2->right),findheight(k2->left))+1; 
	k1->height=max(findheight(k1->right),k2->height)+1;
	return k1; 
}

static avl* doublerotatewithleft(avl *k3)
{ 
	k3->left=singlerotatewithright(k3->left); 
	return singlerotatewithleft(k3);
}

static avl* doublerotatewithright(avl *k3)
{ 
	k3->left=singlerotatewithleft(k3->left); 
	return singlerotatewithright(k3);
}

void inorderdisplay(avl *t)
{
	if(t!=NULL)
	{
		inorderdisplay(t->left);
		printf("English:%s\t\t",t->eng);
		printf("Tamil:%s\t\t",t->tam);
		printf("Hindi:%s\n",t->hindi);
		inorderdisplay(t->right);
	}
}
avl* searchnprint(char eng[],avl *t)
{
	char hin1[15];
	printf("ENter hiin:");
	scanf("%s",hin1);
	int check=0;
	if(t!=NULL)
	{
		if(strcmp(eng,t->eng)==0)
		{
			check=1;
			printf("Word Found!!!\n");
			strcpy(t->hindi,hin1);
			
		}
		else if(strcmp(eng,t->eng)>0)
		{
			searchnprint(eng,t->right);
		}
		else
		{
			searchnprint(eng,t->left);
		}
	}
	if(check==0  && t==NULL)
	{
		printf("Word not found in the dictionary!\n");
	}
}

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

