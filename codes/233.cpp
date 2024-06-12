#include <stdio.h>


extern int max_val, min_val, ave_val;

extern int cal(int *pData, int iLen)
{
    int i;

    if (pData == NULL || iLen < 0)
    {
        return 0;
    }

    for (i = 0; i < iLen; i++)
    {
        if (i == 0)
        {
            max_val = pData[i];
            min_val = pData[i];
            ave_val = 0;
        }
        
        max_val = pData[i] > max_val ? pData[i] : max_val;
        min_val = pData[i] < min_val ? pData[i] : min_val;
        ave_val += pData[i];
    }

    ave_val /= iLen;

    return 1;
}