#include "stdio.h"
#include "string.h"

int main()
{
    int i;

    char a[10001];
    gets(a);

    for (i = strlen(a)-1; i>=0; i--)
    {
        printf("%c", a[i]);
    }
}