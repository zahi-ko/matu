#include <stdio.h>

void xt9_3_5(int *id, float *grade, int length, int accepted) {

    int i, j, temp;
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