#include<stdio.h>
#include<string.h>
void display(char names[50][15],int marks[50][6],int n);
void main()
{
int n;
printf("Enter the number of students:");
scanf("%d",&n);
char names[50][15];
int marks[50][6];
for (int i=0;i<n;i++)
{
printf("Enter the %d student name:",i+1);
scanf("%s",names[i]);
}

for (int i=0;i<n;i++)
{
for (int j=0;j<6;j++)
{
printf("Enter the %d student's %dth mark:",i+1,j+1);
scanf("%d",&marks[i][j]);
}
}
display(names,marks,n);
}
void display(char names[50][15],int marks[50][6],int n)
{
float av=0,classav=0;
printf("name\t");
for(int k=0;k<6;k++)
{
printf("mark%d\t",k+1);
}
printf("Final Score\n");
for (int i=0;i<n;i++)
{
printf("%s\t",names[i]);
for (int j=0;j<6;j++)
{
printf("%d\t",marks[i][j]);
if(j<4)
{
av+=0.15*marks[i][j];
}
else
{
av+=0.20*marks[i][j];
}
}
printf("%.2f",av);
classav+=av;
av=0;
printf("\n");
}
printf("Class Average is:%.2f",classav/n);
}
