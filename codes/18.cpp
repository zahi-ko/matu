#include <stdio.h>
#include <math.h>

int main()
{
    int i;
    int n;
    int flag = 1;

    scanf("%d", &n);

    if (n<=3)
    {
        printf("error");
        return 0;
    }

    for (i=2; i<=sqrt((double)n); i++)
    {
        if (n%i==0)
        {
            flag = 0;
            break;
        }
    }

    if (flag == 1)
    {
        printf("yes");
    }
    else
    {
        printf("no");
    }

    return 0;
}