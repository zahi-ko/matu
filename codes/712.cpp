#include<stdio.h>
#include<malloc.h>

struct Node {
    int data;
    struct Node* next;
};
//头插法：是从头插，根栈一样！！！！

//这里卡了up好久QAQ
Node* CreatList()
{
    Node* header = (Node*)malloc(sizeof(Node));
    header->next = NULL;
    Node* current = header;
    int temp;
    while (1)
    {
        scanf("%d", &temp);
        if (temp == -1) return header;
        else
        {
            Node* next = (Node*)malloc(sizeof(Node));
            next->data = temp;
            next->next = current->next;
            current->next = next;
            
        }
    }
}

void IsCir(Node* first)
{
    Node* mem[2048] = {};
    Node* current = first;
    int i = 0;
    while (1)
    {
        if (current->next == NULL)
        {
            printf("false\n");
            return;
        }
        mem[i++] = current;
        for (int j = 0; j < i; j++)
        {
            if (current->next == mem[j])
            {
                printf("true\n");
                return;
            }
        }
        current = current->next;
    }
}

