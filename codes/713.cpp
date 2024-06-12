#include<stdio.h>
 
typedef struct Node {
    int data;
    struct Node* next;
} Node;

 
void List_sort(Node* head) {
    if (head == NULL || head->next == NULL) {
        return; // ����Ϊ�ջ�ֻ��һ���ڵ㣬����Ҫ����
    }

    Node* current;
    Node* min;
    Node* prev;

    while (head->next != NULL) {
        current = head;
        min = head;
        prev = NULL;

        do {
            if (current->next == NULL) {
                break;
            }
            if (current->next->data < min->data) {
                min = current->next;
            }
            prev = current;
            current = current->next;
        } while (current->next != NULL);

        // ����ͷ�ڵ����Сֵ�ڵ������
        if (min != head) {
            int temp = min->data;
            min->data = head->data;
            head->data = temp;
        }

        // �ƶ�����һ���ڵ�
        head = head->next;
    }
}
 
Node* merge_sorted_lists(Node* head1, Node* head2) {
	Node dummy; // ����һ���ƽڵ㣬��Ϊ�������ͷ��
	Node* tail = &dummy; // tail����ָ������������һ���ڵ�
	dummy.next = NULL;
 
	Node* cur1 = head1->next; // ����ͷ�ڵ�
	Node* cur2 = head2->next; // ����ͷ�ڵ�
 
	while (cur1 != NULL && cur2 != NULL) {
		if (cur1->data < cur2->data) {
			tail->next = cur1;
			cur1 = cur1->next;
		}
		else {
			tail->next = cur2;
			cur2 = cur2->next;
		}
		tail = tail->next;
	}
 
	// ��ʣ�ಿ�ֽӵ��������β��
	if (cur1 != NULL) {
		tail->next = cur1;
	}
	else if (cur2 != NULL) {
		tail->next = cur2;
	}
 
	// ����ʹ�����ƽڵ㣬���������ͷ�ڵ���dummy.next
	head1->next = dummy.next; // ���ϲ��������ӻ�head1��ͷ�ڵ�
	return head1; // ���غϲ���������ͷ�ڵ�
}