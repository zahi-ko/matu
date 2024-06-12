#include<stdio.h>
 
typedef struct Node {
    int data;
    struct Node* next;
} Node;

 
void List_sort(Node* head) {
    if (head == NULL || head->next == NULL) {
        return; // 链表为空或只有一个节点，不需要排序
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

        // 交换头节点和最小值节点的数据
        if (min != head) {
            int temp = min->data;
            min->data = head->data;
            head->data = temp;
        }

        // 移动到下一个节点
        head = head->next;
    }
}
 
Node* merge_sorted_lists(Node* head1, Node* head2) {
	Node dummy; // 创建一个哑节点，作为新链表的头部
	Node* tail = &dummy; // tail用于指向新链表的最后一个节点
	dummy.next = NULL;
 
	Node* cur1 = head1->next; // 跳过头节点
	Node* cur2 = head2->next; // 跳过头节点
 
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
 
	// 将剩余部分接到新链表的尾部
	if (cur1 != NULL) {
		tail->next = cur1;
	}
	else if (cur2 != NULL) {
		tail->next = cur2;
	}
 
	// 由于使用了哑节点，最终链表的头节点是dummy.next
	head1->next = dummy.next; // 将合并后的链表接回head1的头节点
	return head1; // 返回合并后的链表的头节点
}