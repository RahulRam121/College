#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct personalaccount
{
	char name[15],email[30],mob_no[11],acc_no[17];
	char gender;
	int age;
	struct personalaccount *left,*right;
	int height;
}avl;

avl* createacc();
static int findheight(avl *tree);
avl* insertacc(char name1[],char name2[],char name3[],char name4[],char char1,int ag, avl *t);
int max(int a,int b);
static avl* singlerotatewithleft(avl *k2);
static avl* singlerotatewithright(avl *k2);
static avl* doublerotatewithleft(avl *k3);
static avl* doublerotatewithright(avl *k3);
void inorderdisplay(avl *t);

static int findheight(avl *tree)
{
	if(tree==NULL)
		return -1;
	else
		return tree->height;
}

avl* createacc()
{	
	char name1[15],name2[30],name3[11],name4[17];
	char char1;
	int ag;
	avl *tree=NULL;
		printf("Enter your Details !\n");	
		printf("Name :");
		scanf("%s",name1);
		printf("Age :");
		scanf("%d",&ag);
		printf("Gender (m)Male/(f)Female/(o)Others :");
		scanf(" %c",&char1);
		printf("Email :");
		scanf("%s",name2);
		printf("Mobile Number :");
		scanf("%s",name3);
		printf("Bank Acoount Number :");
		scanf("%s",name4);
		printf("\n");
		tree=insertacc(name1,name2,name3,name4,char1,ag,tree);
	
	return tree;
	
}

avl* insertacc(char name1[],char name2[],char name3[],char name4[],char char1,int ag,avl *t) 
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
			strcpy(t->name,name1); 
			strcpy(t->email,name2);
			strcpy(t->mob_no,name3);
			strcpy(t->acc_no,name4);
			t->gender=char1;
			t->age=ag;
			t->height=0; 
			t->left=t->right=NULL;
		}
	}
	else if(strcmp(name1,t->name) < 0)
	{
		t->left=insertacc(name1,name2,name3,name4,char1,ag,t->left);
		if(findheight(t->left) - findheight(t->right) == 2)
		{
			if(strcmp(name1,t->left->name) < 0)
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
	else if(strcmp(name1,t->name) > 0)
	{
		t->right=insertacc(name1,name2,name3,name4,char1,ag,t->right);
		if(findheight(t->left) - findheight(t->right) == 2)
		{
			if(strcmp(name1,t->right->name) > 0)
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
		printf("Name :%s \nAge : %d\nGender : %c\nEmail : %s\nMobile Number : %s\nAccount Number : %s\n",t->name,t->age,t->gender,t->email,t->mob_no,t->acc_no);
		inorderdisplay(t->right);
	}
}

int main()
{
	avl *tree=createacc();
	inorderdisplay(tree);
	return 0;
}
