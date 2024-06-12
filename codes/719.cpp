#include<stdio.h>
 
void isValid(const char* s)
{
	if (s == NULL)
	{
		printf("error");
		return;
	}
 
	//±ß´¢´æ±ßÅÐ¶Ï
	char mem[100] = {};
	int count = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ']' || s[i] == '}' || s[i] == ')')
		{
			
			if (s[i] == ']' && mem[count - 1] != '[')
			{
				printf("false");
				return;
			}
			else if (s[i] == '}' && mem[count - 1] != '{')
			{
				printf("false");
				return;
			}
			else if (s[i] == ')' && mem[count - 1] != '(')
			{
				printf("false");
				return;
			}
			else mem[--count] = '\0';
		}
		if (s[i] == '[' || s[i] == '{' || s[i] == '(' )
		{
			mem[count++] = s[i];
		}
	}
	if (count != 0)		printf("false");
	else				printf("true");
	return;
}