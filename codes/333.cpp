#include <stdio.h>

void xt9_3_5(int * id, float * score, int size, int m) {
    int i = 0;
    int j = 0;
    for (; i < size - 1; i++) {
        j = 0;
        for (; j < size - i - 1; j++) {
            if (score[j] < score[j + 1]) {
                *(int*)&score[j] = *(int*)&score[j] ^ *(int*)&score[j + 1];
                *(int*)&score[j + 1] = *(int*)&score[j] ^ *(int*)&score[j + 1];
                *(int*)&score[j] = *(int*)&score[j] ^ *(int*)&score[j + 1];
                *(int*)&id[j] = *(int*)&id[j] ^ *(int*)&id[j + 1];
                *(int*)&id[j + 1] = *(int*)&id[j] ^ *(int*)&id[j + 1];
                *(int*)&id[j] = *(int*)&id[j] ^ *(int*)&id[j + 1];
            }
        }
    }
    i = 0;
    for (; i < m; i++) {
        printf("%-5d%5.1f\n", id[i], score[i]);
    }
    printf("lowestgrade=%.1f", score[m - 1]);

}
