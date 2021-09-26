#include<stdio.h>
#include<string.h>

#include"prototype.h"
#include"functions.h"

int main()
{
	student stu[20];
	int n=0;
	int sel;
	printf("Press\n1.Insert Record at front.\n2.Insert a record at the end of the list.\n3.Insert a record after a given Regno in the list.\n4.Search a given record in the list based on Name.\n5.Delete a given student record.\n6.Display all student's record.\n7.Display the previous and next record of a given student.\n8.Exit.\n");
	scanf("%d",&sel);
	while(sel!=8)
	{
		switch(sel)
		{
			case 1:insertfront(stu,&n);break;
			case 2:insertlast(stu,&n);break;
			case 3:insertmiddle(stu,&n);break;
			case 4:search(stu,&n);break;
			case 5:delete(stu,&n);break;
			case 6:displayall(stu,&n);break;
			case 7:displaypnrec(stu,&n);break;
			case 8:return 0;
			default:printf("Invalid Input!\n");
		}
	printf("Press\n1.Insert Record at front.\n2.Insert a record at the end of the list.\n3.Insert a record after a given Regno in the list.\n4.Search a given record in the list based on Name.\n5.Delete a given student record.\n6.Display all student's record.\n7.Display the previous and next record of a given student.\n8.Exit.\n");
	scanf("%d",&sel);	
	}
	return 0;
}
