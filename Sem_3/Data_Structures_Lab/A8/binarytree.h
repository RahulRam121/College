typedef struct binarytree
{
	char name[25];
	struct binarytree *right,*left;
}bst;

bst* createtree();
bst* insert(char sname[],bst *hd1);
void display(bst* tree);
bst* findGP(char name[],bst *hd);
void findGC(bst* hd);
bst* findSiblings(char name[],bst *hd);
bst* deleteNode(char name[],bst *hd);
bst* findMin(bst *hd);
bst* findPos(char name[],bst* hd);

bst* createtree()
{
	char tempname[25];
	int ch=1;
	bst *hd = NULL;
	while(ch==1)
	{
		printf("Enter the name :");
		scanf("%s",tempname);
		hd=insert(tempname,hd);
		printf("Continue(1.Yes/2.No) :");
		scanf("%d",&ch);
	}
	return hd;
}

bst* insert(char sname[],bst *hd1)
{
	if(hd1==NULL)
	{
		hd1=(bst *)malloc(sizeof(bst));
		strcpy(hd1->name,sname);
		hd1->left=hd1->right=NULL;
	}
	else if(strcmp(hd1->name,sname)<0)
		hd1->right=insert(sname,hd1->right);
	else if(strcmp(hd1->name,sname)>0)
		hd1->left=insert(sname,hd1->left);
	else
		printf("Name already used! Try Another..\n");
	return hd1;
}

void display(bst* tree)
{
	if(tree!=NULL)
	{
		display(tree->left);
		printf("%s\n",tree->name);
		display(tree->right);
	}
}

bst* findGP(char aname[],bst *hd)
{
	if(hd==NULL)
		return hd;
	if(hd->left!=NULL)
	{
		if(hd->left->left!=NULL)
		{
			if(!strcmp(hd->left->left->name,aname))
				return hd;
		}
		if(hd->left->right!=NULL)
		{
			if(!strcmp(hd->left->right->name,aname))
				return hd;
		}
	}
	if(hd->right!=NULL)
	{
		if(hd->right->left!=NULL)
		{
			if(!strcmp(hd->right->left->name,aname))
				return hd;
		}
		if(hd->right->right!=NULL)
		{
			if(!strcmp(hd->right->right->name,aname))
				return hd;
		}
	}
	if(strcmp(aname,hd->name)<0)
		hd=findGP(aname,hd->left);
	else if(strcmp(aname,hd->name)>0)
		hd=findGP(aname,hd->right);
	
}


void findGC(bst* hd)
{
	int s=0;
	if(hd->left!=NULL && hd->left->left!=NULL)
	{
		s=1;
		printf("%s, ",hd->left->left->name);
	}
	if(hd->left!=NULL && hd->left->right!=NULL)
	{
		s=1;
		printf("%s, ",hd->left->right->name);
	}
	if(hd->right!=NULL && hd->right->left!=NULL)
	{
		s=1;
		printf("%s, ",hd->right->left->name);
	}
	if(hd->right!=NULL && hd->right->right!=NULL)
	{
		s=1;
		printf("%s, ",hd->right->right->name);
	}
	if(s==0)
	{
		printf("Not found!!!");
	}
}

bst* findSiblings(char name[],bst *hd)
{
	bst* temp;
	int f=0;
	temp=(bst *)malloc(sizeof(bst));
	temp=findPos(name,hd);
	if(temp!=NULL)
		f=1;
	if(f==1)
	{
		if(hd==NULL)
			return NULL;
		else if(strcmp(name,hd->left->name)<0)
			return findSiblings(name,hd->left);
		else if(strcmp(name,hd->right->name)>0)
			return findSiblings(name,hd->right);
		return hd;
	}
	else
		printf("%s is not found\n",name);
}

bst* deleteNode(char name[],bst *hd)
{
	bst *tempnode;
	if(hd==NULL)
	{
		printf("Name not found!\n");
	}
	else if(strcmp(name,hd->name)<0)
	{
		hd->left=deleteNode(name,hd->left);
	}
	else if(strcmp(name,hd->name)>0)
	{
		hd->right=deleteNode(name,hd->right);
	}
	else if(hd->left && hd->right)
	{
		tempnode=findMin(hd->right);
		strcpy(hd->name,tempnode->name);
		hd->right=deleteNode(hd->name,hd->right);
	}
	else
	{
		tempnode=hd;
		if(hd->left==NULL)
		{
			hd=hd->right;
		}
		else if(hd->right==NULL)
		{
			hd=hd->left;
		}
		free(tempnode);
	}	
	return hd;
}

bst* findMin(bst *hd)
{
	if(hd==NULL) 
		return NULL;
	else if(hd->left==NULL)
		return hd;
	else
		return findMin(hd->left);
}

bst* findPos(char name[],bst* hd)
{
if (hd==NULL)
	return NULL;
else if (strcmp(name,hd->name)<0)
	return findPos(name,hd->left);
else if (strcmp(name,hd->name)>0)
	return findPos(name,hd->right);
else
	return hd;
}
