#include <stdio.h>

/**
 * 对数组进行排序
 * 
 * @param arr 数组
 * @param n 数组的大小
 */
void sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

/**
 * 找到数组中第k大的元素
 * 
 * @param arr 数组
 * @param n 数组的大小
 * @param k 第k大的元素
 * @return 第k大的元素的值
 */
int findkth(int arr[], int n, int k) {
    sort(arr, n);
    return arr[k - 1];
}

int main() {
    int n, k;
    int arr[16];

    printf("请输入数组的大小：");
    scanf("%d", &n);

    printf("请输入数组的元素：");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("请输入要查找的第k大的元素：");
    scanf("%d", &k);

    printf("第%d大的元素是：%d\n", k, findkth(arr, n, k));
}