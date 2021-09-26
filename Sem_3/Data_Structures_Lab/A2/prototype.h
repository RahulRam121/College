typedef struct 
{
	int regno,mark[5];
	char name[20];
}student;

void insertfront(student *s,int *n);
void insertlast(student *s,int *n);
void insertmiddle(student *s,int *n);
void search(student *s,int *n);
void delete(student *s,int *n);
void displayall(student *s,int *n);
void displaypnrec(student *s,int *n);
