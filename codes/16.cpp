#include <stdio.h>

int main()
{
    int i;

    float prec;
    float PI = 2.0;
    float plus = 1.0;

    scanf("%f", &prec);

    for (i = 1;; i++)
    {
        plus *= ((float)i / (2 * i + 1));
        PI += plus * 2.0;

        if (plus * 2.0 < prec)
        {
            break;
        }
    }

    printf("%.6f", PI);

    return 0;
}