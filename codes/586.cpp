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

    // ����ͷ���
    struct node *head = (struct node*)malloc(sizeof(struct node));
    if (head == NULL) {
        printf("error\n");
        return NULL;
    }
    head->next = NULL; // ͷ����nextָ���ʼ��ΪNULL

    // ������������ಿ��
    struct node *current = head;
    for (int i = 0; i < n; ++i) {
        struct node *newNode = (struct node*)malloc(sizeof(struct node));
        if (newNode == NULL) {
            printf("error\n");
            // �ͷ�֮ǰ�����Ľڵ�
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

        // ���½ڵ����ӵ�������
        current->next = newNode;
        current = newNode;
    }

    return head;
}
