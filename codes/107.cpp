// #include "stdio.h"
#ifndef NULL
#ifdef __cplusplus
#ifndef _WIN64
#define NULL 0
#else
#define NULL 0LL
#endif /* W64 */
#else
#define NULL ((void *)0)
#endif
#endif
int ReverseArray(int array[], int size)
{
    int i;
    int temp;

    if (size <= 0 || array == NULL)
    {
        return 0;
    }

    for (i = 0; i < size / 2; i++)
    {
        temp = array[i];
        array[i] = array[size - i - 1];
        array[size - i - 1] = temp;

    }

    return 1;
}

// int main()
// {
//     int arr[] = {8, 2, 6, 5, 3, 2, 1, 3, 6, 3, 2};
//     ReverseArray(arr, 11);
//     for (int i = 0; i < 11; i++)
//     {
//         printf("%d,", arr[i]);
//     }
// }