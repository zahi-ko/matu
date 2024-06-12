#include "stdio.h"


struct Person
{
    int no;
    int age;
    int height;
};

void swap(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void sort(struct Person *array, int n)
{
    if (array == NULL || n <= 0)
    {
        printf("error");
        return;
    }

    int i = 0;
    int j = 0;
    int flag = 0;


    for(; j < n - 1; j++)
    {
        for (i = 0; i < n - 1 - j; i++)
        {
            flag = 0;
            if (array[i].no > array[i+1].no) {flag = 1;}
            else if (array[i].no == array[i+1].no && array[i].age > array[i+1].age) {flag = 1;}
            else if (array[i].no == array[i+1].no && array[i].age == array[i+1].age && array[i].height > array[i+1].height) {flag = 1;}

            if (flag)
            {
                swap(&array[i].no, &array[i+1].no);
                swap(&array[i].age, &array[i+1].age);
                swap(&array[i].height, &array[i+1].height);
            }
        }
    }
}