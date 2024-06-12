#include <stdio.h>
#include <stdlib.h>

#define null -1
#define INVALID -2


typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *parent;
} TreeNode;


int left(int n, int i, int *arr) {
    int index = i * 2 + 1;
    if (index >= n || arr[index] == null) return INVALID;
    return arr[index];
}

int right(int n, int i, int *arr) {
    int index = i * 2 + 2;
    if (index >= n || arr[index] == null) return INVALID;
    return arr[index];
}

TreeNode* create(int val, TreeNode* parent) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    if (node == NULL || val == -1) return NULL;

    node->val = val;
    node->left = NULL;
    node->right = NULL;
    node->parent = parent;

    return node;
}

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

int iterThrough(TreeNode* node, TreeNode** queue, int iter) {
    if (node == NULL) return 0;
    else queue[iter] = node;
    return 1;
}

TreeNode* buildTree(int *levelOrder, int n) {
    int iter = 0;
    TreeNode** nodesQueue = (TreeNode**)calloc(n, sizeof(TreeNode*));
    
    TreeNode* node = create(levelOrder[0], NULL);
    buildChild(node, n, 0, levelOrder);
    iter += iterThrough(node, nodesQueue, iter);
    iter += iterThrough(node->left, nodesQueue, iter);    
    iter += iterThrough(node->right, nodesQueue, iter);
    

    int max = n;
    for (int i = 1; i < max; i++) {
        max -= buildChild(nodesQueue[i], n, i, levelOrder);

        iter += iterThrough(nodesQueue[i]->left, nodesQueue, iter);
        iter += iterThrough(nodesQueue[i]->right, nodesQueue, iter);
    }
    
    return node;
}

int findLeaves(TreeNode** leaves, TreeNode* root) {
    if (root == NULL) return 0;
    static int leavesNum = 0;

    if (root->left == NULL && root->right == NULL) leaves[leavesNum++] = root;
    findLeaves(leaves, root->left);
    findLeaves(leaves, root->right);

    return leavesNum;
}

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