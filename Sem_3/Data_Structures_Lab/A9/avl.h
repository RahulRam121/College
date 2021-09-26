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
void searchnprint(char eng[],avl *t);
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

void searchnprint(char eng[],avl *t)
{
	int check=0;
	if(t!=NULL)
	{
		if(strcmp(eng,t->eng)==0)
		{
			check=1;
			printf("Word Found!!!\n");
			printf("Eqivalent Tamil Word:%s\n",t->tam);
			printf("Eqivalent Hindi Word:%s\n",t->hindi);
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
