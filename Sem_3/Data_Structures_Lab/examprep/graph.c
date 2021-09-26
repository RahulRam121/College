#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"stack.h"

typedef struct graph1
{
	int value;
	struct graph1 *next;
}graph;

void display(graph* head[],int n);
graph* addedge(graph* head,int val);
graph* addedge(graph* head,int val);
void dfs(graph* head[],int n);

int main(){
	int num,val,ch=1;
	printf("Enter the number of nodes :");
	scanf("%d",&num);	
	graph* head[num];
	for(int i=0;i<num;i++){
		head[i]=malloc(sizeof(graph));
		printf("Enter node %d :",i+1);
		scanf("%d",&val);
		head[i]->value=val;
		head[i]->next=NULL;
	}
	int src,dest;
	while(ch==1){
		printf("Enter src and dest :");
		scanf("%d %d",&src,&dest);
		for(int i=0;i<num;i++){
			if(head[i]->value==src){
				head[i]=addedge(head[i],dest);
			}
		}
		printf("Continue(1.Yes/2.No) :");
		scanf("%d",&ch);
	}
	display(head,num);
	dfs(head,num);
	return 0;
}

graph* addedge(graph* head,int val){
	graph* temp=malloc(sizeof(graph));
	temp->value=val;
	temp->next=head->next;
	head->next=temp;
	return head;
}

void display(graph* head[],int n){
	graph *temp;
	for(int i=0;i<n;i++){
		temp=head[i]->next;
		printf("%d ",head[i]->value);
		while(temp!=NULL){
			printf("-> %d",temp->value);
			temp=temp->next;
		}
		printf("\n");
	}
}
void dfs(graph* head[],int n){
	int visited[n];
	int visits=0;
	int v,present;
	stack* top=NULL;
	top=push(head[0]->value,top);
	while(top!=NULL){
		v=pop(&top);
		int flag=0;
		for(int i=0;i<visits;i++){
			if(v==visited[i]){
				flag=1;
			}
		}
		if(flag==0){
			visited[visits++]=v;
			for(int i=0;i<n;i++){
				if(head[i]->value==v){
			//		present=i;
			//	}
			//}
			graph *temp=head[i/*present*/]->next;
			while(temp!=NULL){
				int x=temp->value;
				//int flag1=0;
				//for(int i=0;i<visits;i++){
				//	if(visited[i]==x){
				//		flag1=1;
				//	}
				//}
				//if(flag1==0){
					top=push(x,top);
				//}
				temp=temp->next;
			}
			}			
		}
	}
		
	}
	for(int i=0;i<visits;i++){
			printf(" %d",visited[i]);
		}
		printf("\n");		
}
