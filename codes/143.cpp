#include <stdio.h>
#include <string.h>

int main()
{
    int i;
    int a = 0;
    int b = 0;
    char words[50];

    scanf("%s", &words);

    for (i = 0; i < strlen(words); i++ )
    {
        if (words[i]=='a')
        {
            a++;
        }
        if (words[i]=='d')
        {
            b++;
        }
    }

    printf("a:%d,d:%d", a, b);

    return 0;
}