#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct hashtable{
	char key[25];
	struct hashtable *next;
}hash;

int findkey(char value[]){
	int total = 0;
	for(int i=0;i<strlen(value);i++){
		total+=value[i];
	}
	return (total%10);
}

hash* hashing(hash* tab,char val[]){
	hash *table = tab;
	if(table == NULL){
		table = malloc(sizeof(hash));
		strcpy(table->key,val);
		table->next=NULL;
		return table;
	}
	
	else{
		while(table->next!=NULL){
			table = table->next;			
		}
		table->next = malloc(sizeof(hash));
		strcpy(table->next->key,val);
		table->next->next=NULL;
	}
	return tab;
}

int main(){
	hash *table[10]; //= malloc(sizeof(hash)*10);
	for(int i=0;i<10;i++){
		table[i] = NULL;
	}	
	
	char values[10][10] = {"rahul","ram","rama","keyss","kum"};
	for(int i=0;i<5;i++){
		int k = findkey(values[i]);
		printf("%d\n",k);
		table[k] = hashing(table[k],values[i]);
	}
	for(int i=0;i<10;i++){
		if(table[i]!=NULL){
			printf("\n%d->",i);
			hash *tab = table[i];
			while(tab!=NULL){
				printf("%s",tab->key);
				tab=tab->next;
			}
		}
	}
	return 0;
}

