#include "stdio.h"
#include "ctype.h"
#include "string.h"

int qualified(char a)
{
    // 规范isalnum的返回值
    return isalnum(a) ? 1 : 0;
}

int main()
{
    int i;
    int count = 0;

    char string[258];
    string[0] = ' ';
    gets(string+1);

    for (i = 0; i < strlen(string); i++)
    {
        if (i > 0 && (qualified(string[i]) - qualified(string[i - 1]) == 1))
        {
            count++;
        }
    }
    printf("%d", count);
}