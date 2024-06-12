#include <stdio.h>


int main()
{
    int year, month;
    scanf("%d %d", &year, &month);

    month = month % 12 == 0 ? 12 : month % 12;

    if (month == 2)
    {
        if (year % 400 == 0 || (year % 4 ==0 && year %100 != 0))
        {
            printf("days:29");
        }
        else
        {
            printf("days:28");
        }
    }
    else if ( (month <= 7 && month % 2 != 0) || ( month >= 8 && month % 2 == 0) )
    {
        printf("days:31");
    }
    else
    {
        printf("days:30");
    }

    return 0;
}
