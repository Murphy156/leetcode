/*
 * date ：2023/10/17
 * title：反转链表
 * brief：反转一个单链表。
 * example：
 *          input  ： 1->2->3->4->5->NULL
 *          output ： 5->4->3->2->1->NULL
*/

/*
 * 思路：
 *      其实只需要改变链表的next指针的指向，直接将链表反转 ，而不用重新定义一个新的链表，
 *   
*/


#include <stdlib.h>
#include <stdio.h>

typedef struct ListNode
{
    int val;
    struct ListNode* next;
}ListNode;

struct ListNode* ReverseList(struct ListNode* head)
{
    ListNode* temp;
    ListNode* cur = head;
    ListNode* pre = NULL;
    while (cur) // 这里只要是指针不为空，就可进入while
    {
        temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    return pre;
}


int main() {
    // 创建一个简单的链表用于测试
    struct ListNode* node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node5 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node6 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node7 = (struct ListNode*)malloc(sizeof(struct ListNode));

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
    node6->next = node7;

    node7->val = 6;
    node7->next = NULL;

    // 测试移除指定值节点函数
    printf("Original List:\n");
    struct ListNode* current = node1;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");

    struct ListNode* modifiedList = ReverseList(node1);
printf("ReverseList List:\n");
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
    free(node7);

    return 0;
}

