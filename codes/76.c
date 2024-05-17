#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

/**
 * 根据前序遍历和中序遍历序列重建二叉树。
 *
 * 该函数接受前序遍历和中序遍历序列作为输入,并返回重建的二叉树根节点。
 *
 * @param preorder 前序遍历序列
 * @param inorder 中序遍历序列
 * @param n 序列长度
 * @return 重建的二叉树根节点
 */
TreeNode *restore(char preorder[], char inorder[], int n);

/**
 * 以后序遍历的方式打印二叉树的所有节点。
 *
 * @param root 二叉树的根节点
 */
void postTraverse(TreeNode *root);


TreeNode* restore(char preorder[], char inorder[], int n) {
    if (n <= 0 || !preorder || !inorder) return NULL;

    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->data = *preorder;

    int rootIndex = 0;
    for (; rootIndex < n; rootIndex++) { if (inorder[rootIndex] == *preorder) break; }
	// 找到根节点在中序遍历中的位置
    if (rootIndex >= n) { printf("error\n"); return NULL; }

	// 依次递归构建左、右子树
    root->left = restore(preorder + 1, inorder, rootIndex);
    root->right = restore(preorder + rootIndex + 1, inorder + rootIndex + 1, n - rootIndex - 1);

    return root;
}

void postTraverse(TreeNode* root) {
    if (root == NULL) return;
    postTraverse(root->left);
    postTraverse(root->right);
    printf("%c", root->data);
}

int main() {
    char preorder[2048];
    char inorder[2048];

    scanf("%s", preorder);
    scanf("%s", inorder);

    if (strlen(preorder) != strlen(inorder)) { printf("error\n"); return 1; }
    
    TreeNode* root = restore(preorder, inorder, strlen(preorder));
    postTraverse(root);
}
