#include <stdio.h>

// Êä³ö£º3 ,9 20 ,15 7 

void hierTraversal(int n, int nodes, int checked, char first) {
    if (checked >= n) return;

    if (first != 'y') putchar(',');
    int tmp;
    int nullCount = 0;
    for (int i = 0; i < nodes && checked < n; i++) {
        scanf("%d", &tmp);
        if (tmp == -1) nullCount++;
        else printf("%d ", tmp);
        checked++;
    }
    int nextNodes = 2 * (nodes - nullCount);
    hierTraversal(n, nextNodes, checked, 'n');
}

int main() {
    int n;
    scanf("%d", &n);
    hierTraversal(n, 1, 0, 'y');
}