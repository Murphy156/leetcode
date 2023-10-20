/*
 * date ：2023/10/20
 * title：删除链表的倒数第N个节点
 * brief：给定一个链表，删除链表的倒数第n个结点，并且返回链表的头节点
 * example：
 *          input  : head = [1,2,3,4,5]， n = 2 
 *          output : [1,2,3,5]
 *          input  ：[1], n = 1
 *          output ：[]
 *          input  ：[1,2], n = 1
 *          output ：[1]
*/


#include <stdlib.h>
#include <stdio.h>

/** typedef的用法是定义最后的那个ListNode */
/** struct 是定义第一个那个ListNode */
typedef struct ListNode{
    int val;
    struct ListNode* next;
}ListNode;

/** 思路：
 *      双指针法，让快指针领先于慢指针，差值是要删除的值，然后同时移动
 */

/** 如果没有用到typedef重命名的话，使用这个结构体要加上struct，如果有的话则不需要 */

ListNode* DeleteTheLastELE(ListNode* head,int n)
{
    ListNode* fast;
    ListNode* slow;
    /**  在C语言中，结构体指针的初始化时通常不能使用结构体内部的元素。你需要先分配内存空间给结构体，然后才能访问和设置结构体内部的成员。有几种方法可以初始化结构体指针： */
    ListNode* fakeNode = (ListNode*)malloc(sizeof(ListNode)) ;
    fakeNode -> val  = 0;
    fakeNode -> next = head;
    /** 直接指向了head */
    fast = head;
    slow = fakeNode;
    /** 移动fast指针n+1 */
    for(int i = 0;i < n;i++)
    {
        fast = fast -> next;
    }
    while(fast){
        fast = fast -> next;
        slow = slow -> next;
    }
    slow -> next = slow -> next -> next; /** 删除节点 */
    head = fakeNode -> next;
    free(fakeNode);
    return head;
}

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

    struct ListNode* modifiedList = DeleteTheLastELE(node1,3);
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


