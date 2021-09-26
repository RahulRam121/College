#include<stdio.h>
int main(int argc,char *argv[])
{
	FILE *fp1;
	fp1=fopen(argv[1],"r");
	if(fp1==NULL)
	{
		printf("File does not exist");
		return 0;
	}
	else
	{
		FILE *fp2;
		fp2=fopen(argv[2],"r");
		if(fp2==NULL)
		{
			fclose(fp2);
			fp2=fopen(argv[2],"w");
			char c;
			while(c=getc(fp1)!=EOF)
			{
				putc(c,fp2);
			}
			fclose(fp1);
			fclose(fp2);
			printf("Copied successfully");
			return 0;
		}
		else
		{
			fclose(fp2);
			int a;
			printf("Press\n1.Overwrite\n2.Append\n");
			scanf("%d",&a);
			if(a==1)
			{
				fp2=fopen(argv[2],"w");
				char c;
				while(c=getc(fp1)!=EOF)
				{
					putc(c,fp2);
				}
				fclose(fp1);
				fclose(fp2);
				printf("Overwrite Completed");
				return 0;
			}
			else if(a==2)
			{
				fp2=fopen(argv[2],"a");
				char c;
				while(c=getc(fp1)!=EOF)
				{
					putc(c,fp2);
				}
				fclose(fp1);
				fclose(fp2);
				printf("Appended Successfully");
				return 0;
			}
			else
			{
				printf("Invalid Input");
			}
		}
	}
}
