// ; 给定一个元素不超过20的整数数组 numbers ，该数组已按非递减顺序排列，请你从数组中找出满足相加之和等于目标数 target 的两个数。
// ; 如果设这两个数分别是 numbers[index1] 和 numbers[index2] ，则 1 <= index1 < index2 <= numbers.length 。
// 以长度为 2 的整数数组 [index1, index2] 的形式返回这两个整数的下标 index1 和 index2。
// ; 从键盘输入数组元素个数、数组元素以及目标整数，用空格分开；
// ; 输出符合要求的两个整数的下标 index1 和 index2，输出用“,”分开
// ; 如果没有符合要求的结果，输出：No solution found.

#include <stdio.h>

int main() {
    int size;
    int target;
    int numbers[20];
    int index1, index2;
    index1 = -1;

    scanf("%d", &size);
    for (int i=0; i<size; i++) { scanf("%d", numbers+i); }
    scanf("%d", &target);

    for (int i=0; i<size; i++) {
        for (int j=i+1; j<size;j++) {
            if ( numbers[i]+numbers[j] == target ) {
                index1 = i+1;
                index2 = j+1;
                goto outside;
            }
        }
    }

    outside:
    if (index1 == -1) { printf("No solution found.\n");}
    else { printf("%d,%d\n", index1, index2); }
}