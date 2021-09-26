#include <stdio.h>
int main()
{
   FILE *fp;

   fp = fopen("test.txt", "r+");
   fprintf(fp, "This is rahul\n");
   fclose(fp);
}   
