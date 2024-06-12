#include <stdio.h>

int main()
{
    int n;
    int mul;
    int i, j;
    int sum = 0;

    scanf("%d", &n);

    if (n >= 1 && n <= 10)
    {
        for (i = 1; i <= n; i++)
        {
            mul = 1;
            for (j = 1; j <= i; j++)
            {
                mul *= j;
            }
            sum += mul;
        }
        printf("%d\n", sum);
    }
    else
    {
        printf("error");
    }

    return 0;
}