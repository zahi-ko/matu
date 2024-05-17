#include <stdio.h>


/**
 * @param nodes 当前层需要遍历的节点数目
 * @param checked 已经遍历过的节点数目
 * @param n 总的节点数目
 * @return 二叉树的最大深度
 */
int detectDepth(int nodes, int checked, int n)
{
    // 使用静态变量存储层数
    static int depth = 0;
    if (checked >= n)
    {
        // 将depth置零便于多次调用
        int tmp = depth;
        depth = 0;
        return tmp;
    }

    int elem;
    int nullCount = 0;

    // 获取非零节点数
    for (int i = 0; i < nodes && checked < n; i++)
    {
        scanf("%d", &elem);
        // null是以0的形式输入的（观察发现第一个节点名字为1故可推知）
        if (elem == 0)
            nullCount++;
        checked++;
    }

    // 如果当前层不全为空测深度加一
    if (nullCount != nodes)
        depth++;
    // 下层需要遍历的节点数目
    int nextNodes = 2 * (nodes - nullCount);
    // 递归获取最大深度
    return detectDepth(nextNodes, checked, n);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", detectDepth(1, 0, n));
}