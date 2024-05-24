#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 10

int** divideArr(int *arr) {
    int **ret = (int **)malloc(sizeof(int *) * 2);
    int *odd = (int *)malloc(sizeof(int) * MAXLEN / 2);
    int *even = (int *)malloc(sizeof(int) * MAXLEN / 2);
    int *length = (int *)malloc(sizeof(int) * 2);
    
    length[0] = 0;
    length[1] = 0;

    ret[0] = odd;
    ret[1] = even;
    ret[2] = length;

    for (int i = 0; i < MAXLEN; i++) {
        int tmp = arr[i];
        if (tmp < 0) break;
        if (tmp % 2 == 0) odd[length[0]++] = tmp;
        else even[length[1]++] = tmp;
    }

    return ret;
}

void sort(int *arr, int n) {
    if (arr == NULL || n <= 0) return;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void printSorted(int *arr, int n) {
    sort(arr, n);
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
}

int main() {
    int arr[MAXLEN];
    
    for (int i = 0; i < MAXLEN; i++) {
        scanf("%d", arr + i);
        if (arr[i] < 0) break;
    }

    int **dividedInfo = divideArr(arr);
    printSorted(dividedInfo[1], dividedInfo[2][1]);
    printSorted(dividedInfo[0], dividedInfo[2][0]);
}