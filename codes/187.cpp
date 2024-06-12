#include <stdio.h>


int main()
{
    int const cock_price = 5;
    int const hen_price = 3;
    int const chicken_price = 1;
    int const  money = 100;
    int const sum = 100;

    int i, j, k;

    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 33; j++)
        {
            for (k = 0; k <= 100; k+=3)
            {
                if ( (i+j+k)==100 && (i*cock_price+j*hen_price+k/3*chicken_price == money))
                {
                    printf("%d,%d,%d,", i, j, k);
                }
            }
        }
    }
}