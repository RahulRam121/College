
void addTokens(char token[], char type[]);
void printTokens();
char* getSubString(char line[], int start, int stop);

char tokens[30][50];
char types[30][50];

int tok_size = 0;

void addTokens(char token[], char type[])
{
	strcpy(tokens[tok_size], token);
	strcpy(types[tok_size], type);
	tok_size += 1;
}

void printTokens()
{
	for(int i = 0; i < tok_size; i++)
	{
		printf("%-50s - %s\n", tokens[i], types[i]);
	}
}

char* getSubString(char line[], int start, int stop)
{
	int length = stop - start + 1;
	char *sub;
	int c = 0;
	while (c < length) {
      sub[c] = line[start+c];
      c++;
   }
   sub[c] = '\0';
   return sub;
}
