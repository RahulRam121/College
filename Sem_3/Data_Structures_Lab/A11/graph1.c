#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include"stack.h"

typedef struct newgraph{
	char vertices;
	struct newgraph *link;
}graph;

/*typedef struct visitednode{
	char nodes;
	struct visitednode *next;
}vnode;*/


void dfs(graph *node[],int v);
graph* addedge(char dest);
void printgraph(graph *node[],int n);

int main(){
	int v,ch=1,ud;
	char src,dest;
	printf("1.Directed Graph/2.Undirected Graph  :");
	scanf("%d",&ud);	
	printf("Enter the number of nodes : ");
	scanf("%d",&v);
	graph *node[100];
	printf("Enter the vertices in order\n");
	char c;
	for(int i=0;i<v;i++)
	{
		node[i]=(graph *)malloc(sizeof(graph));
		printf("Enter vertex number %d :",i+1);
		scanf(" %c",&c);		
		node[i]->vertices=c;
		node[i]->link = NULL;
	}
	while(ch==1){
		printf("Enter the source      : ");
		scanf(" %c", &src);
		printf("Enter the destination : ");
		scanf(" %c", &dest);
		for(int i=0;i<v;i++){
			if(node[i]->vertices==src){
				graph *temp=addedge(dest);
				temp->link=node[i]->link;				
				node[i]->link=temp;
			}
			if(ud==2){
				if(node[i]->vertices==dest){
					graph *temp=addedge(src);
					temp->link=node[i]->link;				
					node[i]->link=temp;						
				}
			}
		}
		printf("Continue(1.Yes/2.No)? : ");
		scanf("%d",&ch);
	}
	printgraph(node,v);
	dfs(node,v);
	return 0;
}

graph* addedge(char dest){
	graph *edge=(graph *)malloc(sizeof(graph));
	edge->vertices=dest;
	edge->link=NULL;
	return edge;
}

void printgraph(graph *node[],int n){
	graph *node1[n];
	for(int i=0;i<n;i++){
		node1[i]=node[i];	
	}
	
	printf("Displaying Graph's Adjacency List!\n");
	for(int j=0;j<n;j++){
		printf("head");
		while(node1[j]!=NULL){
			printf("->%c",node1[j]->vertices);
			node1[j]=node1[j]->link;
		}
		printf("\n");
	} 
}

void dfs(graph *node[],int v){
	stack *top;
	int present;
	top = NULL;
	int visits=0;
	char visited[v];
	
	
	//vnode *stack=(vnode *)malloc(sizeof(vnode));
	//vnode->nodes=NULL;
	//stack->next=NULL;
	top=push(node[0]->vertices,top);
	while(top!=NULL){
		char x=pop(&top);
		int flag1=0;
		for(int i=0;i<visits;i++){ 
			if(visited[i]==x){
				flag1=1;
			}
		}
		if(flag1==0){
			visited[visits++]=x;			
			for(int i=0;i<v;i++){
				if(node[i]->vertices==x){
					present=i;
				}
			}
			node[present]=node[present]->link;
			while(node[present]!=NULL){
				char y=node[present]->vertices;
				int flag2=0;
				for(int i=0;i<v;i++){
					if(node[i]->vertices==y){
						flag2=1;
					}					
				}	
				if(flag2==0){
					top=push(y,top);
				}
				node[present]=node[present]->link;
			}
		
		}
			
		}
		for(int i=0;i<visits;i++){
			printf(" %c",visited[i]);
		}
	}
	/*int flag=0;
	for(int i=0;i<v;i++){
		if(node[i]->link!=NULL){
			flag=1;
		}		
	}	
	if(flag == 0){
		printf("No element inserted!\n");
		return;
	}
	for(int i=0;i<b;i++){
		push(stack,node[i]);
		while(stack!=NULL){
			graph *newnode = (graph *)malloc(sizeof(graph));
			newnode=pop(stack,node[i]);
			for(int j=0;j<v;j++){
				if(newnode->vertices!=visited[j]){
					append(visited,newnode->vertices);
										
				}
			}
		}
	}
}*/
