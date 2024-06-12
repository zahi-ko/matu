#include <stdio.h>
void del(char *s, int n, int len)
{
    if (s == NULL || n < 0 || len < 0)
    {
        printf("error\n");
        return;
    }
    int i;
    for (i = 0; i < n + len; i++)
        if (s[i] == ' ')
        {
            printf("error");
            return;
        }
    for (i = n; s[i + len] != '\0'; i++)
        s[i] = s[i + len];
    for (; s[i] != '\0'; i++)
        s[i] = ' ';
    return;
}
