#include <stdio.h>
#include <math.h>

int main()
{
    int i;
    int n = 0;

    scanf("%d", &n);

    for (i = 1; i <= 4; i++)
    {
        printf("%d ", (int) pow((double) n, i));
    }

    printf("%d\n", (int) pow((double) n, 5));

    return 0;
}