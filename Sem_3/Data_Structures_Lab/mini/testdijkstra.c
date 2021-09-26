#include<stdio.h>
#include<conio.h>
#include<string.h>
#define INFINITY 9999
#define MAX 10
 
int dijkstra(int G[MAX][MAX],int n,int startnode,int endnode);
 
int main()
{
	int G[MAX][MAX],i,j,n,s,e,d;
	n=9;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			G[i][j]=0;
	G[0][1]=70;G[0][2]=340;G[1][0]=70;G[1][3]=200;G[2][1]=340;
	G[2][3]=143;G[2][7]=168;G[3][1]=200;G[3][2]=143;G[3][4]=132;
	G[3][8]=59;G[4][3]=132;G[4][5]=157;G[4][7]=236;G[4][8]=206;
	G[5][4]=157;G[5][6]=85;G[6][5]=85;G[6][7]=450;G[7][2]=168;
	G[7][4]=236;G[7][6]=450;G[8][3]=59;G[8][4]=206;
	
	
	char start[20],end[20];
	printf("Start :");
	scanf("%s",start);
	printf("End :");
	scanf("%s",end);
	if(strcmp(start,"chennai")==0){
		s=0;
	}
	else if(strcmp(start,"pondicherry")==0){
		s=1;
	}
	else if(strcmp(start,"salem")==0){
		s=2;
	}
	else if(strcmp(start,"tiruchirapalli")==0){
		s=3;
	}
	else if(strcmp(start,"madurai")==0){
		s=4;
	}
	else if(strcmp(start,"tirunelveli")==0){
		s=5;
	}
	else if(strcmp(start,"kanyakumari")==0){
		s=6;
	}
	else if(strcmp(start,"coimbatore")==0){
		s=7;
	}
	else if(strcmp(start,"tanjore")==0){
		s=8;
	}
	
	if(strcmp(end,"chennai")==0){
		e=0;
	}
	else if(strcmp(end,"pondicherry")==0){
		e=1;
	}
	else if(strcmp(end,"salem")==0){
		e=2;
	}
	else if(strcmp(end,"tiruchirapalli")==0){
		e=3;
	}
	else if(strcmp(end,"madurai")==0){
		e=4;
	}
	else if(strcmp(end,"tirunelveli")==0){
		e=5;
	}
	else if(strcmp(end,"kanyakumari")==0){
		e=6;
	}
	else if(strcmp(end,"coimbatore")==0){
		e=7;
	}
	else if(strcmp(end,"tanjore")==0){
		e=8;
	}
	
	
	/*printf("0.Chennai\n1.puducherry\n2.Salem\n3.Thiruchirapalli\n4.Madurai\n5.Tirunelveli\n6.Kanyakumari\n7.Coimbatore\n8.Tanjore\n")
	printf("Select origin : ");
	scanf("%d",&s);
	printf("Select destination : ");
	scanf("%d",&e);*/
	d=dijkstra(G,n,s,e);
	printf("Distance between %s and %s : %d kms",start,end,d);
	return 0;
}

int dijkstra(int G[MAX][MAX],int n,int startnode,int endnode)
{
 
	int cost[MAX][MAX],distance[MAX],pred[MAX];
	int visited[MAX],count,mindistance,nextnode,i,j;
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(G[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=G[i][j];
	
	for(i=0;i<n;i++)
	{
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}
	
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;
	
	while(count<n-1)
	{
		mindistance=INFINITY;
	
		for(i=0;i<n;i++)
			if(distance[i]<mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}			
			visited[nextnode]=1;
			for(i=0;i<n;i++)
				if(!visited[i])
					if(mindistance+cost[nextnode][i]<distance[i])
					{
						distance[i]=mindistance+cost[nextnode][i];
						pred[i]=nextnode;
					}
		count++;
	}

	return distance[endnode];
	/*for(i=0;i<n;i++)
		if(i!=startnode)
		{
			printf("\nDistance of node%d=%d",i,distance[i]);
			printf("\nPath=%d",i);
			
			j=i;
			do
			{
				j=pred[j];
				printf("<-%d",j);
			}while(j!=startnode);
	}*/
}
