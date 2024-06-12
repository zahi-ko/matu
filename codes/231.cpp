#include "stdlib.h"
#include "stdio.h"

int fun(const char *p, int result[])
{
    if (p[13] != '\0' || p == NULL || result == NULL)
    {
        return 0;
    }

    char year[5];
    char school[3];
    char classes[5];
    char stu[4];

    int i;
    for (i = 0; i < 13; i++)
    {
        if (p[i] < 48 || p[i] > 57)
        {
            return 0;
        }

        if (i <= 3)
        {
            year[i] = p[i];
        }
        else if (i <= 5)
        {
            school[i-4] = p[i];
        }
        else if (i <= 9)
        {
            classes[i-6] = p[i];
        }
        else
        {
            stu[i-10] = p[i];
        }
    }

    result[0] = atoi(year);
    result[1] = atoi(school);
    result[2] = atoi(classes);
    result[3] = atoi(stu);

    return 1;
}