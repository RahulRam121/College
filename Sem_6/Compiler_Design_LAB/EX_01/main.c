#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "list.h"
#include "data.h"
#include "token_list.h"

#define MAX_LEN 100

int main()
{
	struct table *head = NULL;
	char line[100];
	char temp_line[100];
	char temp[MAX_LEN];
	
	int left, right, v_index, len;
	int address = 1000;
	
    char dt[10];  		// datatype
    char var[5][15];	// variables
    char val[5][10];	// its value
    
    char mCom[MAX_LEN];	// multi line comment
    strcpy(mCom, "");

	FILE *file = fopen ("input.txt", "r");  

	
	while (fgets(line, MAX_LEN, file))
    {
    	left = 0, right = 0, v_index = -1;
    	len = strlen(line);
    	
    	strcpy(dt, "");
    	
    	for(int i = 0; i < 5; i++)
    	{
    		strcpy(var[i], "");
    		strcpy(val[i], "");
		}
    	
    	strcpy(temp_line, line);
    	
    	// multi line comment
    	if(strcmp(mCom, "") != 0)
    	{
    		if(strstr(line, "*/") != NULL)
    		{
    			temp[strcspn(temp, "\n")] = 0;
				strcpy(temp, getSubString(temp_line, 0, len-4));
				strcpy(temp_line, line);
				addTokens(temp, "multi line comment");
				strcpy(mCom, "");
			}
			else
			{
				line[strcspn(line, "\n")] = 0;
    			addTokens(line, "multi line comment");
			}
			left = len;
		}
    	
    	while(left < len)
    	{
    		right = left;
    		while(right < len)
    		{
    			// get substring from left to right
    			strcpy(temp, getSubString(temp_line, left, right));
    			strcpy(temp_line, line);
    			
    			// leading spaces
    			// move right to len, to move left towards right
    			if(left == right && line[left] == ' ')
    			{
    				right = len;
				}
				// single line comment
				else if(strcmp(temp, "//") == 0)
				{
					strcpy(temp, getSubString(temp_line, right+1, len-1));
					strcpy(temp_line, line);
					temp[strcspn(temp, "\n")] = 0;
					addTokens(temp, "single line comment");
					left = len, right = len;
				}
				// mutli line comment
				else if(strcmp(temp, "/*") == 0)
				{
					strcpy(temp, getSubString(temp_line, right+1, len-1));
					strcpy(temp_line, line);
					temp[strcspn(temp, "\n")] = 0;
					addTokens(temp, "multi line comment");
					strcpy(mCom, temp);
					left = len, right = len;
				}
				// for identifiers, keywords and constants
				// if right == delimiters and left not equal to right(not a character)
				else if(checkDelimiters(line[right]) && left != right)
				{
					// get substring before the delimiter
					strcpy(temp, getSubString(temp_line, left, right-1));
					strcpy(temp_line, line);
					// check if it is a keyword
					if(checkKeywords(temp))
					{
						// add token
						addTokens(temp, "keyword");
						// check if it is a datatype
						if(checkDatatypes(temp))
						{
							// copy the datatype to dt
							strcpy(dt, temp);
						}					
					}
					// not a keyword - could be identifier or constants
					// starting alphabets - identifier (except string or char)
					else if(isalpha(temp[0]))
					{
						// copy the identifer and add token
						strcpy(var[++v_index], temp);
						addTokens(temp, "identifier");
					}
					// else it has to be constants(not detailed)
					else
					{
						// copy the value and add appropriate token
						strcpy(val[v_index], temp);
						if(strcmp(dt, "int") == 0)
						{
							addTokens(temp, "integer constant");
						}
						else if(strcmp(dt, "float") == 0)
						{
							addTokens(temp, "float constant");
						}
						else
						{
							addTokens(temp, "double constant");
						}
						
					}
					// moving left, next to the current word using below 2 assignments
					left = right-1;
					right = len;
				}
				// for single characters 
				else if(checkDelimiters(line[right]) && right == left)
				{
					// if it is not the last character of the line (2 character ops)
					if(right != len-1)
					{
						// get the next character along with the current one in the substring
						strcpy(temp, getSubString(temp_line, left, right+1));
						strcpy(temp_line, line);
						// check if it matches any ops 
						// if yes - move left next to the op
						if(checkArith_assign_op(temp))
						{
							addTokens(temp, "arithmetic assignment operator");
							left = right+1;
							right = len;
						}
						else if(checkLogical_op(temp))
						{
							addTokens(temp, "logical operator");
							left = right+1;
							right = len;
						}
						else if(checkRelational_op(temp))
						{
							addTokens(temp, "relational operator");
							left = right+1;
							right = len;
						}
						else if(checkBitwise_op(temp))
						{
							addTokens(temp, "bitwise operator");
							left = right+1;
							right = len;
						}
						else if(checkUnary_op(temp))
						{
							addTokens(temp, "unary operator");
							left = right+1;
							right = len;
						}
						// one character ops
						else
						{
							// get only the current character
							strcpy(temp, getSubString(temp_line, left, right));
							strcpy(temp_line, line);
							// check for the ops and add token
							// if yes - move left next to the op
							if(checkArithmetic_op(temp))
							{
								addTokens(temp, "arithmetic operator");
								left = right;
								right = len;
							}
							else if(strcmp(temp, "=") == 0)
							{
								addTokens(temp, "assignment operator");
								left = right;
								right = len;
							}
							else if(checkRelational_op(temp))
							{
								addTokens(temp, "relational operator");
								left = right;
								right = len;
							}
							else if(checkBitwise_op(temp))
							{
								addTokens(temp, "bitwise operator");
								left = right;
								right = len;
							}
							else if(checkUnary_op(temp))
							{
								addTokens(temp, "unary operator");
								left = right;
								right = len;
							}
							else if(checkSpecial_char(temp))
							{
								addTokens(temp, "special character");
								left = right;
								right = len;
							}
							// if none matches -  error
							else
							{
								strcpy(temp, getSubString(temp_line, left, len-1));
								strcpy(temp_line, line);
								temp[strcspn(temp, "\n")] = 0;
								addTokens(temp, "error");
								// error skip the current line
								left = len;
								right = len;
							}
						}
					}
					// single character op
					else
					{
						// same as else part
						strcpy(temp, getSubString(temp_line, left, right));
						strcpy(temp_line, line);
						if(checkArithmetic_op(temp))
						{
							addTokens(temp, "arithmetic operator");
							left = right;
							right = len;
						}
						else if(strcmp(temp, "=") == 0)
						{
							addTokens(temp, "assignment operator");
							left = right;
							right = len;
						}
						else if(checkRelational_op(temp))
						{
							addTokens(temp, "relational operator");
							left = right;
							right = len;
						}
						else if(checkBitwise_op(temp))
						{
							addTokens(temp, "bitwise operator");
							left = right;
							right = len;
						}
						else if(checkUnary_op(temp))
						{
							addTokens(temp, "unary operator");
							left = right;
							right = len;
						}
						else if(checkSpecial_char(temp))
						{
							addTokens(temp, "special character");
							left = right;
							right = len;
						}
						else
						{
							strcpy(temp, getSubString(temp_line, left, len-1));
							strcpy(temp_line, line);
							temp[strcspn(temp, "\n")] = 0;
							addTokens(temp, "error");
							left = len;
							right = len;
						}
					}
				}
				// char constant
				else if(line[right] == '\'' && left == right)
				{
					strcpy(temp, getSubString(temp_line, right+1, right+1));
					strcpy(temp_line, line);
					strcpy(val[v_index], temp);
					addTokens(temp, "char constant");
					left = right+2;
					right = len;
				}
				// string constant
				else if(line[right] == '"' && left == right)
				{
					int lst = -1;
					for(int i = right+1; i < len; i++)
					{
						if(line[i] == '"')
						{
							lst = i;
							break;
						}
					}
					if(lst != -1)
					{
						strcpy(temp, getSubString(temp_line, left+1, lst-1));
						strcpy(temp_line, line);
						addTokens(temp, "string constant");
						left = lst;
						right = len;
					}
					else
					{
						strcpy(temp, getSubString(temp_line, left, len-1));
						strcpy(temp_line, line);
						temp[strcspn(temp, "\n")] = 0;
						addTokens(temp, "error");
						// error skip the current line
						left = len;
						right = len;
					}
				}
				// preprocessor directive
    			else if(checkHash(temp) && left == right)
    			{
    				line[strcspn(line, "\n")] = 0;
    				addTokens(line, "preprocessor directive");
    				left = len, right = len;
				}
				
				// function call and conditions
				else if(line[right] == '(')
				{
					strcpy(temp, getSubString(temp_line, left, right-1));
					strcpy(temp_line, line);
					
					bool isfun = true;
					int last = len;	
					
					// inbuilt
					if(checkKeywords(temp))
					{
						addTokens(temp, "keyword");
						addTokens("(", "special character");
						left = right;
						right = len;
						break;
					}
					
					if(isalpha(temp[0]))
					{
						for(int i = 1; i < strlen(temp); i++)
						{
							if(!isalpha(temp[i]) && !isdigit(temp[i]) && temp[i] != '_')
							{
								isfun = false;
								break;
							}
						}
					}
					else
					{
						isfun = false;
					}
					
					if(isfun)
					{
						for(int i = right; i < len; i++)
						{
							if(line[i] == ')')
							{
								last = i+1;
								break;
							}
						}
						strcpy(temp, getSubString(temp_line, left, last-1));
						strcpy(temp_line, line);
						temp[strcspn(temp, "\n")] = 0;
						addTokens(temp, "function call");
						
						left = last-1;
						right = len;
					}
					else
					{
						strcpy(temp, getSubString(temp_line, left, len-1));
						strcpy(temp_line, line);
						temp[strcspn(temp, "\n")] = 0;
						addTokens(temp, "error in function call");
						left = len, right = len;
					}
						
				}
				
    			right++;
			}
			left++;
		}
		int bytes = 0;
		for (int j = 0; j < 4; j++)
		{
			if(strcmp(dt, datatypes[j]) == 0)
			{
				bytes = datatypeVal[j];
				break;
			}
		}
		for(int i = 0; i <= v_index; i++)
		{
			if(strcmp(dt, "") != 0)
			{
				addRow(&head, var[i], dt, bytes, address, val[i]);
	    		address += bytes;
			}
	    }
	}
	printTokens();
	printTable(head);
	return 0;
}

int main1()
{
	char string[] = "sdfsdfaAA";
	char sub[30];
	//printf("%s\n",match(string, fun_regex) ? "true" : "false");
	return 0;
}
