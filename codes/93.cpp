#include <stdio.h>
#include <ctype.h>

int main()
{
    // When scanf get an alpha, the int will be auto-set to zero.
    int i;
    int j;
    int max = 0;
    int flag = 1;

    scanf("%d", &max);

    if (max <= 1)
    {
        printf("error");
    }

    else
    {
        for (i = 2; i <= max; i++)
        {
            flag = 1;

            for (j = 2; j < i; j++)
            {
                if (i % j == 0)
                {
                    flag = 0;
                    break;
                }
            }

            if (flag == 1)
            {
                printf("%d,", i);
            }
        }
    }

    return 0;
}