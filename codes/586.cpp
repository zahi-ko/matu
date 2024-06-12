#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* createList(int data[], int n) {
    if (n <= 0) {
        printf("error\n");
        return NULL;
    }

    // 创建头结点
    struct node *head = (struct node*)malloc(sizeof(struct node));
    if (head == NULL) {
        printf("error\n");
        return NULL;
    }
    head->next = NULL; // 头结点的next指针初始化为NULL

    // 创建链表的其余部分
    struct node *current = head;
    for (int i = 0; i < n; ++i) {
        struct node *newNode = (struct node*)malloc(sizeof(struct node));
        if (newNode == NULL) {
            printf("error\n");
            // 释放之前创建的节点
            while (current != head) {
                struct node *temp = current;
                current = current->next;
                free(temp);
            }
            free(head);
            return NULL;
        }
        newNode->data = data[i];
        newNode->next = NULL;

        // 将新节点链接到链表中
        current->next = newNode;
        current = newNode;
    }

    return head;
}
