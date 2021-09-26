#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct binarytree{
	int value;
	struct binarytree *left,*right;
}bst;

bst* insertbst(bst* top,int val);
void display(bst* head);
bst* deletenode(int val,bst* head);
bst* findmin(bst* head);
int findsiblings(bst* head,int v);

int main(){
	bst* head=NULL;
	int val;
	for(int i=0;i<6;i++){
		printf("enter the value : ");
		scanf("%d",&val);
		head=insertbst(head,val);
	}
	display(head);
	printf("Enter a value : ");
	scanf("%d",&val);
	head=deletenode(val,head);
	display(head);
	printf("Enter to siblings :");
	scanf("%d",&val);	
	int v=findsiblings(head,val);
	if(v!=-1 && v!=-2)
		printf("sibling : %d",v);
	else
		printf("No siblings\n");
	return 0;
}

bst* insertbst(bst* top,int val){
	if(top==NULL){
		top=(bst *)malloc(sizeof(bst));
		top->value=val;
		top ->right=top->left=NULL;
	}
	else if(val<top->value){
		top->left=insertbst(top->left,val);
	}
	else if(val>top->value){
		top->right=insertbst(top->right,val);
	}
	else{
		printf("Duplicate key\n");
	}
	return top;
}

void display(bst* head){
	if(head!=NULL){
		display(head->left);
		printf("%d",head->value);
		display(head->right);
	}
}

bst* deletenode(int val,bst* head){
	bst* temp;
	if(head==NULL){
		printf("NOT FOUND!\n");
	}
	else if(val<head->value){
		head->left=deletenode(val,head->left);
	}
	else if(val>head->value){
		head->right=deletenode(val,head->right);
	}
	else if(head->left&&head->right){
		temp=findmin(head->right);
		head->value=temp->value;
		head->right=deletenode(val,head->right);
	}
	else{
		temp=head;
		if(head->left==NULL){
			head=head->right;
		}
		else if(head->right){
			head=head->left;
		}
		free(temp);		
	}
	return head;
}

bst* findmin(bst* head){
	if(head==NULL)
		return head;
	else if(head->left==NULL)
		return head;
	else
		return findmin(head->left);
}

int findsiblings(bst* head,int v){
	if(head==NULL)
		return -1;
	else if(head->value==v || head->left==NULL || head->right==NULL)
		return -2;		
	else if(head->left->value==v)
		return head->right->value;		
	else if(head->right->value==v)
		return head->left->value;	
	else if(v<head->value)
		return findsiblings(head->left,v);				
	else if(v>head->value)
		return findsiblings(head->right,v);
}
