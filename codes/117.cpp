#include "string.h"
#include "stdlib.h"
#include "ctype.h"

void del(char *s)
{
    int i;
    int k = 0;
    char *cp = (char *)calloc(strlen(s) + 1, sizeof(char));

    for (i = 0; s[i] != '\0'; i++)
    {
        if (!isalnum(s[i]) && (s[i] == s[i + 1]))
        {
            continue;
        }

        cp[k++] = s[i];
    }

    strcpy(s, cp);
    free(cp);
}