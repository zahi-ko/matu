#include <stdio.h>
#include <stdlib.h>

// 定义常量
#define null -1
#define INVALID -2

// 定义树节点
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *parent;    // 定义父节点的指针，便于后面求和
} TreeNode;

/**
 * 获取当前节点的左子节点
 * @param n 节点个数
 * @param i 当前节点的索引
 * @param arr 节点数组
 * @return 左子节点的值
 */
int left(int n, int i, int *arr) {
    int index = i * 2 + 1;
    if (index >= n || arr[index] == null) return INVALID;
    return arr[index];
}

/**
 * 获取当前节点的右子节点
 * @param n 节点个数
 * @param i 当前节点的索引
 * @param arr 节点数组
 * @return 右子节点的值
 */
int right(int n, int i, int *arr) {
    int index = i * 2 + 2;
    if (index >= n || arr[index] == null) return INVALID;
    return arr[index];
}

/**
 * 创建树节点
 * @param val 节点的值
 * @param parent 父节点
 * @return 树节点
*/
TreeNode* create(int val, TreeNode* parent) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    if (node == NULL || val == null) return NULL;

    node->val = val;
    node->left = NULL;
    node->right = NULL;
    node->parent = parent;

    return node;
}

/**
 * 构建树节点的子节点
 * @param node 父节点
 * @param n 节点个数
 * @param i 当前节点的索引
 * @param arr 节点数组
 * @return 子节点中的NULL个数
*/
int buildChild(TreeNode* node, int n, int i, int* arr) {
    if (node == NULL) return 0;
    
    int res = 0;

    int val = left(n, i, arr);
    if (val != INVALID) node->left = create(val, node);
    else { node->left = NULL; res++; }

    val = right(n, i, arr);
    if (val!= INVALID) node->right = create(val, node);
    else { node->right = NULL; res++; }

    return res;
}

/**
 * 遍历树节点
 * @param node 树节点
 * @param queue 队列
 * @param iter 迭代次数
 * @return iter增长的次数
*/
int iterThrough(TreeNode* node, TreeNode** queue, int iter) {
    if (node == NULL) return 0;
    else queue[iter] = node;
    return 1;
}

/**
 * 构建树
 * @param levelOrder 层序遍历的结果
 * @param n 节点个数
*/
TreeNode* buildTree(int *levelOrder, int n) {
    int iter = 0;
    TreeNode** nodesQueue = (TreeNode**)calloc(n, sizeof(TreeNode*));   // 用来存储依次要构建子树的节点
    
    TreeNode* node = create(levelOrder[0], NULL);
    buildChild(node, n, 0, levelOrder);
    // 添加节点到队列中
    iter += iterThrough(node, nodesQueue, iter);
    iter += iterThrough(node->left, nodesQueue, iter);    
    iter += iterThrough(node->right, nodesQueue, iter);
    

    int max = n;
    for (int i = 1; i < max; i++) {
        // 实时地调整迭代的次数
        max -= buildChild(nodesQueue[i], n, i, levelOrder);
        // 依次添加当前节点的左、右节点到队列中
        iter += iterThrough(nodesQueue[i]->left, nodesQueue, iter);
        iter += iterThrough(nodesQueue[i]->right, nodesQueue, iter);
    }
    
    return node;
}

/**
 * 先序遍历二叉树，找到叶子节点
 * @param leaves 叶子节点数组
 * @param root 根节点
 * @return 叶子节点的个数
*/
int findLeaves(TreeNode** leaves, TreeNode* root) {
    if (root == NULL) return 0;
    static int leavesNum = 0;

    if (root->left == NULL && root->right == NULL) leaves[leavesNum++] = root;
    findLeaves(leaves, root->left);
    findLeaves(leaves, root->right);

    return leavesNum;
}

/**
 * 计算树的和
 * @param root 根节点
 * @param n 节点个数
 * @return 树的和
*/
int sumNodes(TreeNode* root, int n) {
    int sum = 0;

    unsigned leavesNum = (n + 1) / 2;
    TreeNode** leaves = (TreeNode**)malloc(sizeof(TreeNode*) * leavesNum);
    leavesNum = findLeaves(leaves, root);

    for (int i = 0; i < leavesNum; i++) {
        int rate = 10;

        TreeNode* leaf = leaves[i];
        sum += leaf->val;

        TreeNode* leafParent = leaf->parent;
        while (leafParent != NULL) {
            // 通过循环获取当前路径的值
            sum += rate * leafParent->val;
            leafParent = leafParent->parent;
            rate *= 10;
        }
    }
    return sum;   
}

void readInput(int n, int *arr) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);
    readInput(n, arr);
    
    int index = 0;
    TreeNode* root = buildTree(arr, n);
    printf("%d\n", sumNodes(root, n));
   
}