#include "stdio.h"

void minmax(int s[])
{
    int i = 0;
    int min = 100;
    int max = 0;
    int avg = 0;

    for (; i < 10; i++)
    {
        avg += s[i];
        min = s[i] > min ? min : s[i];
        max = s[i] > max ? s[i] : max;
    }

    avg /= 10;
    printf("%d,%d,%d", min, max, avg);
}

int main()
{
    int i;
    int s[10];

    for (i = 0; i < 10; i++)
    {
        scanf("%d", &s[i]);
    }

    minmax(s);

}