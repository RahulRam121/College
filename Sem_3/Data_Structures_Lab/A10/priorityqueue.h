typedef struct priorityqueue{
	int capacity,size;
	struct details *array;
}pq;

typedef struct details{
	float salary;
	char name[25];
	int id;	
}det;

pq* createPQ(int maxele);
void display(pq *h1);
void display2(det temp);
int isFull(pq *h1);
int isEmpty(pq *h1);
pq* insert(char name1[],int id2,float sal1,pq *h1);
det deletemax(pq *h1);

pq* createPQ(int maxele){
	pq *h1;
	h1=(pq *)malloc(sizeof(pq));
	if(h1==NULL){
		printf("Fatal Error: Out of space!\n");
	}
	h1->array=(det *)malloc(sizeof(det)*(maxele+1));
	if(h1->array==NULL){
		printf("Fatal Error: Out of space!\n");	
	}
	h1->capacity=maxele;
	h1->array[0].salary=0;
	h1->array[0].id=0;
	strcpy(h1->array[0].name,"<empty>");
	h1->size=0;
	return h1;
}

pq* insert(char name1[],int id2,float sal1,pq *h1){
	int i;
	if(isFull(h1)){
		printf("Queue is full!\n");
		return h1;
	}
	for(i=++h1->size;h1->array[i/2].salary<sal1 && h1->array[i/2].salary!=0;i/=2){
		h1->array[i]=h1->array[i/2];
	}
	strcpy(h1->array[i].name,name1);
	h1->array[i].id=id2;
	h1->array[i].salary=sal1;
	return h1;
}

det deletemax(pq *h1)
{
	int i, child;
	det minelement,lastelement;
	if(isEmpty(h1)){
		printf("PQueue is empty\n");
		return (h1->array[0]);
	}
	minelement=h1->array[1];
	lastelement=h1->array[h1->size--];
	for(i=1;(i*2) <= h1->size;i=child){
		child=i*2;
		if(child!=h1->size && h1->array[child+1].salary > h1->array[child].salary)
			child++;
		if(lastelement.salary < h1->array[child].salary)
			h1->array[i]=h1->array[child];
		else
			break;
	}
	h1->array[i]=lastelement;
	return minelement; 
}

void display(pq *h1){
	printf("Displaying Tree!!!\n");
	for(int i=1;i<=(h1->size);i++){
		printf("%d : %s\t%d\t%.2f\n",i,h1->array[i].name,h1->array[i].id,h1->array[i].salary);
	}
}

void display2(det temp){
	printf("Displaying Highest Salary Employee!!!\n");
	printf("Name   : %s\nID     : %d\nSalary : %.2f\n",temp.name,temp.id,temp.salary);
}

int isFull(pq *h1){
	if(h1->size==h1->capacity){
		return 1;
	}
	return 0;
}

int isEmpty(pq *h1){
	if(h1->size==0){
		return 1;
	}
	return 0;
}
