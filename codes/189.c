#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *arr, int length, int target) {
    int start = 0;

    while (start < length) {
        int mid = (start + length) / 2;
        if (arr[mid] == target) return mid + 1;
        else if (arr[mid] > target) length = mid;
        else start = mid + 1;
    }

    return -1;
}

int main() {
    int n, x;
    scanf("%d ", &n);

    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) scanf("%d,", &arr[i]);

    scanf("%d", &x);

    printf("%d\n", binarySearch(arr, n, x));
}