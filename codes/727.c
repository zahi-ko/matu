#include <stdio.h>

/**
 * 基本思路同 714.c
 * @param n 总的节点数目
 * @param nodes 当前层需要遍历的节点数目
 * @param checked 已经遍历过的节点数目
 * @param first 是否为初次进入函数（以便正确打印结果）
 * @return 二叉树的最大深度
 */
void hierTraversal(int n, int nodes, int checked, char first) {
    if (checked >= n) return;
    // 每一层要用逗号分隔开来
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