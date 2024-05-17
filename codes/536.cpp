#include <map>

/**
 * 同时进行二叉树构建、左右子树的交换、以及先序遍历
 * @param preOrder 先序遍历序列
 * @param indexMap 中序遍历中每个节点值对应的索引
 * @param res 存储交换后的先序遍历序列
 * @param preStart 先序遍历的起始位置
 * @param preEnd 先序遍历的结束位置
 * @param inStart 中序遍历的起始位置
 * @param inEnd 中序遍历的结束位置
 * @return 交换后的先序遍历序列
 */
int* swapson(int* preOrder, std::map<int, int>& indexMap, int* res, int preStart, int preEnd, int inStart, int inEnd) {
    // 退出条件
    if (preStart > preEnd)
        return res;

    // res的更新顺序为根节点、左子树、右子树，即先序遍历

    *res++ = preOrder[preStart];    // 先序遍历根节点
    int rootIndex = indexMap[preOrder[preStart++]];     // 查询根节点在中序遍历中的位置

    //! 不可以删去下方的res =，虽然传入的是指针，res的值应该是可以动态更新的，但是码图说不。

    // 构建左子树（实际上是原来的二叉树的右子树）
    res = swapson(preOrder, indexMap, res, preEnd + (rootIndex - inEnd) + 1, preEnd, rootIndex + 1, inEnd);
    // 构建右子树（实际上是原来的二叉树的左子树）
    res = swapson(preOrder, indexMap, res, preStart, preStart + (rootIndex - inStart) - 1, inStart, rootIndex - 1);

    return res;
}

/*
*   如果改写为如下形式，最终得分只有90（原因不明），所以无法用纯C实现
*    int *pos = (int*)calloc(n, sizeof(int));
*    for (int i = 0; i < n; i++)
*        pos[inOrder[i]] = i;
*/
void solve(int n, int* preOrder, int* inOrder, int* outOrder) {
    // 使用映射结构，便于快速查找根节点的位置
    std::map<int, int> pos;
    for (int i = 0; i < n; i++)
        pos[inOrder[i]] = i;
    
    swapson(preOrder, pos, outOrder, 0, n - 1, 0, n - 1);
}