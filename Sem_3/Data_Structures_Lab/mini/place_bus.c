#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct places
{
	char place[15];
	int no_buses;
	char buses[10][15];
	struct places *next;	
}llist;

llist* insertplace_bus(llist* head, char place1[], char bus[][15],int nob);
void displaybuses(llist *head);
llist* createplace_bus();
void comparebuses(char bus1[][15],char bus2[][15],int nob1,int nob2,char bus[10][15]);
void findbuses(char origin[],char destination[],char bus[10][15],llist *head);

llist* insertplace_bus(llist* head, char place1[], char bus[][15],int nob) //nob = no of bus
{ 
    llist* new_node = (llist*) malloc(sizeof(llist)); 
    strcpy(new_node->place,place1);
    new_node->no_buses=nob;
    for(int i=0;i<nob;i++)
    {
    	strcpy(new_node->buses[i],bus[i]);
	}
    new_node->next = head; 
    head = new_node; 
    return head;
}

void displaybuses(llist *head)
{
	printf("%d",head->no_buses);
	while(head!=NULL)
	{
		printf("%s ->",head->place);
		for(int i=0;i<head->no_buses;i++)
		{
			printf("%s, ",head->buses[i]);
		}
		printf("\n");
		head=head->next;
	}
}

llist* createplace_bus()
{
	int num;
	char place1[15],bus[10][15];
	int nob;
	llist *head=NULL;	
	printf("Enter the number of places :");
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		printf("Enter Place %d details\n",i+1);
		printf("Place Name :");
		scanf("%s",place1);
		printf("Number of bus :");
		scanf("%d",&nob);
		for(int j=0;j<nob;j++){
			printf("Bus %d Name :",j+1);
			scanf("%s",bus[j]);
		}
		head=insertplace_bus(head,place1,bus,nob);
	}
	return head;
}

void findbuses(char origin[],char destination[],char bus[10][15],llist *head)
{
	char bus1[10][15],bus2[10][15];
	int nob1,nob2;
	while(head!=NULL){
		if(strcmp(head->place,origin)==0){
			for(int i=0;i<head->no_buses;i++){
				strcpy(bus1[i],head->buses[i]);
			}
			nob1=head->no_buses;
		}
		if(strcmp(head->place,destination)==0){
			for(int j=0;j<head->no_buses;j++){
				strcpy(bus2[j],head->buses[j]);
			}
			nob2=head->no_buses;
		}
		head=head->next;		
	}
	comparebuses(bus1,bus2,nob1,nob2,bus);
}

void comparebuses(char bus1[][15],char bus2[][15],int nob1,int nob2,char bus[10][15])
{
	int x=0;
	for(int i=0;i<nob1;i++){
		for(int j=0;j<nob2;j++){
			if(strcmp(bus1[i],bus2[j])==0){
				strcpy(bus[x++],bus1[i]);
			}
		}
	}
}

int main()
{
	char bus[10][15];
	for(int j=0;j<10;j++){
		strcpy(bus[j],"empty");
	}
	llist *head=createplace_bus();
	displaybuses(head);
	findbuses("chennai","ngl",bus,head);
	for(int i=0;strcmp(bus[i],"empty")!=0;i++){
		printf("Buses -> %s\n",bus[i]);
	}
	return 0;
}
