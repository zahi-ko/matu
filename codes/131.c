#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 10

/**
 * 将数组分成奇数和偶数两部分
 * 
 * @param arr 要分割的数组
 * @return 包含奇数和偶数数组以及长度信息的二维数组
 */
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

/**
 * 对数组进行排序（升序）
 * 
 * @param arr 要排序的数组
 * @param n 数组的长度
 */
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

/**
 * 打印排序后的数组元素
 * 
 * @param arr 要打印的数组
 * @param n 数组的长度
 */
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