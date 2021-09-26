#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct busnames
{
	char bus_name[15],bus_no[7],driver_name[15],mob_no[10];
	char ac,seat;
	int places;
	char place[6][15],starttime[6][6],returntime[6][6];
	float nonac_cost,ac_cost,semi_cost,sleeper_cost;
	int sleeper,semi_sleeper,ratings;
	struct busnames *left,*right;
	int height;
}avl;

static int findheight(avl *tree);
avl* insertbus(char name1[],char name2[],char name3[],char name4[],char names[][15],char times1[][6],char times2[][6],char char1,char char2,float cost1,float cost2,float cost3,float cost4,int am1,int am2,int am3,int nums1, avl *t); 
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

avl* createbus()
{	
	int num;
	int nums1;
	char name1[15],name2[15],name3[15],name4[15],names[6][15],times1[6][6],times2[6][6];
	char char1,char2;
	int amount1,amount2,amount3;
	float cost1,cost2,cost3,cost4;
	avl *tree=NULL;
	printf("Enter the number of buses :");
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		printf("Enter Bus %d Details\n",i+1);	
		printf("Bus name :");
		scanf("%s",name1);
		printf("Bus no :");
		scanf("%s",name2);
		printf("Driver's name :");
		scanf("%s",name3);
		printf("Mobile Number :");
		scanf("%s",name4);
		printf("AC(a)/Non AC(n) :");
		scanf(" %c",&char1);
		printf("Seating (s)Sleeper,(n)Semi Sleeper,(b)Both :");
		scanf(" %c",&char2);
		printf("Sleeper Seats Available :");
		scanf("%d",&amount1);
		printf("Semi Sleeper Seats Available :");
		scanf("%d",&amount2);
		printf("Non AC Rate :");
		scanf("%f",&cost1);
		printf("AC cost :");
		scanf("%f",&cost2);
		printf("Semi Sleeper Cost :");
		scanf("%f",&cost3);
		printf("Sleeper cost :");
		scanf("%f",&cost4);
		printf("Total Places :");
		scanf("%d",&nums1);
		char pp[15],tt1[6],tt2[6];
		for(int x=0;x<nums1;x++)
		{
			printf("Place %d\n",x+1);						
			scanf("%s",pp);
			printf("Start time :");
			scanf("%s",tt1);
			printf("Return time :");
			scanf("%s",tt2);
			strcpy(names[x],pp);
			strcpy(times1[x],tt1);
			strcpy(times2[x],tt2);
		}
		printf("Ratings :");
		scanf("%d",&amount3);
		printf("\n");
		tree=insertbus(name1,name2,name3,name4,names,times1,times2,char1,char2,cost1,cost2,cost3,cost4,amount1,amount2,amount3,nums1,tree);
	}
	return tree;
	
}

avl* insertbus(char name1[],char name2[],char name3[],char name4[],char names[][15],char times1[][6],char times2[][6],char char1,char char2,float cost1,float cost2,float cost3,float cost4,int am1,int am2,int am3,int nums1, avl *t) 
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
			strcpy(t->bus_name,name1); 
			strcpy(t->bus_no,name2);
			strcpy(t->driver_name,name3);
			strcpy(t->mob_no,name4);
			for(int i=0;i<nums1;i++)
			{
				strcpy(t->place[i],names[i]);
				strcpy(t->starttime[i],times1[i]);
				strcpy(t->returntime[i],times2[i]);
			}
			t->ac=char1;
			t->seat=char2;
			t->nonac_cost=cost1;
			t->ac_cost=cost2;
			t->semi_cost=cost3;
			t->sleeper_cost=cost4;
			t->sleeper=am1;
			t->semi_sleeper=am2;
			t->places=nums1;
			t->ratings=am3;
			t->height=0; 
			t->left=t->right=NULL;
		}
	}
	else if(strcmp(name1,t->bus_name) < 0)
	{
		t->left=insertbus(name1,name2,name3,name4,names,times1,times2,char1,char2,cost1,cost2,cost3,cost4,am1,am2,am3,nums1,t->left);
		if(findheight(t->left) - findheight(t->right) == 2)
		{
			if(strcmp(name1,t->left->bus_name) < 0)
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
	else if(strcmp(name1,t->bus_name) > 0)
	{
		t->right=insertbus(name1,name2,name3,name4,names,times1,times2,char1,char2,cost1,cost2,cost3,cost4,am1,am2,am3,nums1,t->right);
		if(findheight(t->left) - findheight(t->right) == 2)
		{
			if(strcmp(name1,t->right->bus_name) > 0)
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
		printf("Bus Name :%s \nAC : %c\nRatings : %d\n",t->bus_name,t->ac,t->ratings);
		for(int i=0;i<(t->places);i++){
			printf("%s =%s & %s",t->place[i],t->starttime[i],t->returntime[i]);
		}
		inorderdisplay(t->right);
	}
}

void searchnprint(char bus[],char place1[],char place2[],float km,avl *t)
{
	
	int check=0;
	if(t!=NULL)
	{
		if(strcmp(bus,t->bus_name)==0)
		{
			check=1;
			//printf("Word Found!!!\n");
			printf("Bus Name :%s\n",t->bus_name);
			printf("Bus Number :%s\n",t->bus_no);
			printf("AC or Non AC :");
			if(t->ac=='a')
			{
				printf("AC\n");				
			}
			else
			{
				printf("Non AC\n");
			}
			printf("Seats :");
			if(t->seat=='s'){
				printf("Sleeper \n");
			}
			else if(t->seat=='n'){
				printf("Semi Sleeper\n");
			}
			else
			{
				printf("Sleeper & Semi Sleeper\n");
			}
			int index1,index2;
			for(int i=0;i<t->places;i++){
				if(strcmp(t->place[i],place1)==0){
					index1=i;
				}
				if(strcmp(t->place[i],place2)==0){
					index2=i;
				}				
			}
			if((index2-index1)>0){
				printf("Starting time :%s\n",t->starttime[index1]);
				printf("Ending time :%s\n",t->starttime[index2]);
			}
			else{
				printf("Starting time :%s\n",t->returntime[index1]);
				printf("Ending time :%s\n",t->returntime[index2]);
			}
			if(t->ac=='a'){
				if(t->seat=='s'){
					printf("Sleeper cost :%.2f\n",((t->ac_cost*km)+(t->sleeper_cost*km)));						
				}
				if(t->seat=='n'){
					printf("Semi Sleeper cost :%.2f\n",((t->ac_cost*km)*(t->semi_cost*km)));						
				}
				else{
					printf("Sleeper cost :%.2f\n",((t->ac_cost*km)+(t->sleeper_cost*km)));
					printf("Semi Sleeper cost :%.2f\n",((t->ac_cost*km)*(t->semi_cost*km)));
				}
			}
			else{
				if(t->seat=='s'){
					printf("Sleeper cost :%d\n",(t->sleeper_cost*km));						
				}
				if(t->seat=='n'){
					printf("Semi Sleeper cost :%d\n",(t->semi_cost*km));						
				}
				else{
					printf("Sleeper cost :%d\n",(t->sleeper_cost*km));						
					printf("Semi Sleeper cost :%d\n",(t->semi_cost*km));						
				}					
			}
			if(t->seat=='s'){
				printf("Sleeper Seats Avalable :%d\n",t->sleeper);
			}
			else if(t->seat=='n'){
				printf("Semi Sleeper Seats Available :%d\n",t->semi_sleeper);
			}
			else{
				printf("Sleeper Seats Avalable :%d\n",t->sleeper);
				printf("Semi Sleeper Seats Available :%d\n",t->semi_sleeper);
			}
			printf("Ratings :%d\n",t->ratings)	;
			
			
		}
		else if(strcmp(bus,t->bus_name)>0)
		{
			searchnprint(bus,place1,place2,km,t->right);
		}
		else
		{
			searchnprint(bus,place1,place2,km,t->left);
		}
	}
	if(check==0  && t==NULL)
	{
		printf("Word not found in the dictionary!\n");
	}
}

int main()
{
	avl *tree=createbus();
	inorderdisplay(tree);
	searchnprint("tat","chennai","ngl",5,tree);
	
	return 0;
}
