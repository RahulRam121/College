
bool checkKeywords(char string[]);
bool checkDatatypes(char string[]);
bool checkArithmetic_op(char string[]);
bool checkArith_assign_op(char string[]);
bool checkLogical_op(char string[]);
bool checkRelational_op(char string[]);
bool checkBitwise_op(char string[]);
bool checkUnary_op(char string[]);
bool checkSpecial_char(char string[]);
bool checkAssign(char string[]);
bool checkHash(char string[]);
bool checkDelimiters(char character);


char keywords[][10] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", 
"float", "for", "goto", "if", "int", "long", "register","return", "short", "signed", "sizeof", "static", "struct",
"switch","typedef", "union", "unsigned", "void", "volatile", "while"};

char datatypes[][7] = {"int", "char", "float", "double"};
int datatypeVal[] = {2, 1, 4, 8};
						
char arithmetic_op[][3] = {"+", "-", "*", "/", "%"};

char arith_assign_op[][3] = {"+=", "-=", "*=", "/=", "%="};

char logical_op[][3] = {"&&", "||", "!"};

char relational_op[][3] = {"<", "<=", ">", ">=", "==", "!="};

char bitwise_op[][3] = {"^", "&", "|", "<<", ">>"};

char unary_op[][3] = {"-", "++", "--"};

char special_char[][3] = {";", ",", ".", "[", "]", "{", "}", "(", ")"};

char delimiters[] = {'+', '-', '*', '%', '&', '|', '!', '<', '>', ' ', ';', ',' ,'{', '}', '[', ']',')', '^', '='};
						
bool checkKeywords(char string[])
{
	for(int i = 0; i < sizeof(keywords)/sizeof(keywords[0]); i++)
	{
		if(strcmp(keywords[i], string) == 0)
		{
			return true;
		}
	}
	return false;
}

bool checkDatatypes(char string[])
{
	for(int i = 0; i < 4; i++)
	{
		if(strcmp(datatypes[i], string) == 0)
		{
			return true;
		}
	}
	return false;
}

bool checkArithmetic_op(char string[])
{
	for(int i = 0; i < 5; i++)
	{
		if(strcmp(arithmetic_op[i], string) == 0)
		{
			return true;
		}
	}
	return false;
}

bool checkArith_assign_op(char string[])
{
	for(int i = 0; i < 5; i++)
	{
		if(strcmp(arith_assign_op[i], string) == 0)
		{
			return true;
		}
	}
	return false;
}

bool checkLogical_op(char string[])
{
	for(int i = 0; i < 3; i++)
	{
		if(strcmp(logical_op[i], string) == 0)
		{
			return true;
		}
	}
	return false;
}

bool checkRelational_op(char string[])
{
	for(int i = 0; i < 6; i++)
	{
		if(strcmp(relational_op[i], string) == 0)
		{
			return true;
		}
	}
	return false;
}

bool checkBitwise_op(char string[])
{
	for(int i = 0; i < 5; i++)
	{
		if(strcmp(bitwise_op[i], string) == 0)
		{
			return true;
		}
	}
	return false;
}

bool checkUnary_op(char string[])
{
	for(int i = 0; i < 3; i++)
	{
		if(strcmp(unary_op[i], string) == 0)
		{
			return true;
		}
	}
	return false;
}

bool checkSpecial_char(char string[])
{
	for(int i = 0; i < 9; i++)
	{
		if(strcmp(special_char[i], string) == 0)
		{
			return true;
		}
	}
	return false;
}

bool checkAssign(char string[])
{
	return strcmp(string, "=") == 0;
}

bool checkHash(char string[])
{
	return strcmp(string, "#") == 0;
}

bool checkDelimiters(char character)
{
	for(int i = 0; i < strlen(delimiters); i++)
	{
		if(character == delimiters[i])
		{
			return true;
		}
	}
	return false;
}
