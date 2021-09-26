#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// a structure to read and write
struct customer {
   char  fname[20],lname[20];
   int   acct_num;
   float acct_balance;
};

/**************************************/
void main ()
{
   FILE *outfile;
   struct customer input;

   // open Accounts file for writing
   outfile = fopen ("accounts.dat","w");
   if (outfile == NULL)
     {
      fprintf(stderr, "\nError opening accounts.dat\n\n");
      exit (1);
     }

   // instructions to user
   printf("Enter \"stop\" for First Name to end program.");

   // endlessly read from keyboard and write to file
   while (1)
     {
      // prompt user
      printf("\nFirst Name: ");
      scanf ("%s", input.fname);
      // exit if no name provided
      if (strcmp(input.fname, "stop") == 0)
         exit(1);
      // continue reading from keyboard
      printf("Last Name : ");
      scanf ("%s", input.lname);
      printf("Acct Num  : ");
      scanf ("%d", &input.acct_num);
      printf("Balance   : ");
      scanf ("%f", &input.acct_balance);

      // write entire structure to Accounts file
      fwrite (&input, sizeof(struct customer), 1, outfile);
     }
}

