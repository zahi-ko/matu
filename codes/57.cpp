#include "ctype.h"
#include "string.h"

int CalString(char *str)
{
    int i;
    int count = 0;

    for (i = 0; i < strlen(str); i++)
    {
        if (!isalnum(str[i]))
        {
            count++;
        }
    }
    
    return count;
}