#include <stdio.h>

/**
 * 对学生的成绩进行排序，并输出前accepted个学生的学号和成绩，
 * 以及最低分数。
 *
 * @param id 学生的学号数组
 * @param grade 学生的成绩数组
 * @param length 学生数组的长度
 * @param accepted 需要输出的学生数量
 */
void xt9_3_5(int *id, float *grade, int length, int accepted) {

    int i, j, temp;
    // 冒泡排序
    for (i = 0; i < length; i++) {
        for (j = i + 1; j < length; j++) {
            if (grade[i] < grade[j]) {
                temp = grade[i];
                grade[i] = grade[j];
                grade[j] = temp;

                temp = id[i];
                id[i] = id[j];
                id[j] = temp;
            }
        }
    }

    for (i = 0; i < accepted; i++) printf("%-5d%5.1f\n", id[i], grade[i]);
    printf("lowestgrade=%.1f", grade[accepted - 1]);
}