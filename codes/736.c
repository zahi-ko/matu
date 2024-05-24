#include <stdio.h>
#include <stdlib.h>


typedef int ElementType;
typedef struct node {
    ElementType data;
    struct node* left;
    struct node* right;
} node;

void preTraverse(node *root);
node* createNode(ElementType data);
node* buildBST(node* root, ElementType data);

int main() {
    int tmp;
    node *root = NULL;

    for (int i = 0; ; i++) {
        scanf("%d", &tmp);
        if (tmp == -1) { break; }
        root = buildBST(root, tmp);
    }

    preTraverse(root);
    printf("\n");
}

node* createNode(ElementType data) {
    node* res = (node*)malloc(sizeof(node));
    if (res == NULL) return res;

    res->data = data;
    res->left = NULL;
    res->right = NULL;

    return res;
}

node* buildBST(node* root, ElementType data) {
    if (root == NULL) return createNode(data);

    if (data <= root->data) root->left = buildBST(root->left, data);
    else root->right = buildBST(root->right, data);

    return root;
}

void preTraverse(node *root) {
    if (root == NULL) return;
    printf("%d ", root->data);

    preTraverse(root->left);
    preTraverse(root->right);
}