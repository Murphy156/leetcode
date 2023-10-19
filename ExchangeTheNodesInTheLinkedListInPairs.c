/*
 * date ：2023/10/19
 * title：两两交换链表中的节点
 * brief：给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * example：
 *          input  : head = [1,2,3,4]
 *          output : [2,1,4,3]
 *          input  ：[]
 *          output ：[]
 *          input  ：[1]
 *          output ：[1]
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct ListNode
{
    int val ;
    struct ListNode* next; 
}ListNode;


struct ListNode* ExchangeLinkElement(struct ListNode* head)
{
    ListNode* fakehead = (ListNode*)malloc(sizeof(ListNode));
    fakehead->next = head;
    ListNode* right = fakehead->next;
    ListNode* left  = fakehead;
    while(left && right && right->next)
    {   
        left->next = right->next;
        right->next = left->next->next;
        /** 这里的理解式left的next的下一节点，注意cur和next的区别*/
        left->next->next = right;
        left = right;
        right = left->next;
    } 
    return fakehead->next;
};

int main() {
    // 创建一个简单的链表用于测试
    struct ListNode* node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node5 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node6 = (struct ListNode*)malloc(sizeof(struct ListNode));


    node1->val = 1;
    node1->next = node2;

    node2->val = 2;
    node2->next = node3;

    node3->val = 6;
    node3->next = node4;

    node4->val = 3;
    node4->next = node5;

    node5->val = 4;
    node5->next = node6;

    node6->val = 5;
    node6->next = NULL;



    // 测试移除指定值节点函数
    printf("Original List:\n");
    struct ListNode* current = node1;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");

    struct ListNode* modifiedList = ExchangeLinkElement(node1);
printf("ExchangeLinkElement List:\n");
    current = modifiedList;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");

    // 释放链表节点的内存
    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(node5);
    free(node6);

    return 0;
}
