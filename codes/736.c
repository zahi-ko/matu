#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct node {
    ElementType data;
    struct node* left;
    struct node* right;
} node;

// Function to perform pre-order traversal of a binary search tree
void preTraverse(node *root);

// Function to create a new node with the given data
node* createNode(ElementType data);

// Function to build a binary search tree
node* buildBST(node* root, ElementType data);

int main() {
    int tmp;
    node *root = NULL;

    // Read input values until -1 is encountered
    for (int i = 0; ; i++) {
        scanf("%d", &tmp);
        if (tmp == -1) { break; }
        root = buildBST(root, tmp);
    }

    // Perform pre-order traversal of the binary search tree
    preTraverse(root);
    printf("\n");
}

// Function to create a new node with the given data
node* createNode(ElementType data) {
    node* res = (node*)malloc(sizeof(node));
    if (res == NULL) return res;

    res->data = data;
    res->left = NULL;
    res->right = NULL;

    return res;
}

// Function to build a binary search tree
node* buildBST(node* root, ElementType data) {
    if (root == NULL) return createNode(data);

    if (data <= root->data) root->left = buildBST(root->left, data);
    else root->right = buildBST(root->right, data);

    return root;
}

// Function to perform pre-order traversal of a binary search tree
void preTraverse(node *root) {
    if (root == NULL) return;
    printf("%d ", root->data);

    preTraverse(root->left);
    preTraverse(root->right);
}