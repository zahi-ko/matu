#include "stdio.h"
#include "stdlib.h"

struct clock
{
    int hour;
    int minute;
    int second;
};

typedef struct clock CLOCK;

int main()
{
    int h, m, s;
    scanf("%d,%d,%d", &h, &m, &s);

    CLOCK *clk = (CLOCK *)malloc(sizeof(CLOCK));
    clk->hour = h;
    clk->minute = m;
    clk->second = s;

    if (clk->second >= 60 || clk->minute >= 60 || clk->hour > 24)
    {
        printf("error");
    }
    else
    {
        printf("%02d:%02d:%02d", clk->hour, clk->minute, clk->second);
    }

    return 0;
}