/*
 * date ：2024/04/01
 * title：K个一组翻转链表
 * brief：给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
 * example：
 *          input  : head = [1,2,3,4,5],k = 2
 *          output : [2,1,4,3,5]
*/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

// 辅助函数：创建一个新的链表节点
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// 辅助函数：反转链表的前k个节点，并返回新的头节点和尾节点的下一个节点
struct ListNode* reverse(struct ListNode* head, int k) 
{
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = NULL;
    int count = 0;
    
    // 检查链表长度是否大于等于k
    struct ListNode* temp = head;
    for (int i = 0; temp != NULL && i < k; ++i, temp = temp->next);
    if (temp == NULL) return head; // 如果长度小于k，不需要翻转
    
    // 翻转前k个节点
    while (curr != NULL && count < k) {
        // 暂存的操作
        next = curr->next;
        // 处理他下一位的指向
        curr->next = prev;
        // 处理prev和curr的问题
        prev = curr;
        curr = next;
        count++;
    }
    
    // 递归处理剩余的链表，并连接到当前翻转的链表、next是当前的head
    if (next != NULL) {
        /**
         * 假设链表是1->2->3->4->5->6，并且k=3，意味着我们每3个节点翻转一次。
         * 当我们对前3个节点进行翻转操作后，链表变为3->2->1和4->5->6（这里假设它们是两个独立的子链表）。
         * 在完成前3个节点的翻转后，head变量指向原来链表的第一个节点（现在是翻转后的最后一个节点，值为1），而next变量指向剩余链表的第一个节点（值为4）。
         * 现在，我们想要翻转剩下的链表4->5->6，这正是reverse(next, k);
         * 做的事情。这个函数调用会翻转剩下的部分（在这个例子中只有3个节点，所以它会变成6->5->4），并返回翻转后子链表的新头节点（值为6）。
         * 所以，当我们执行head->next = reverse(next, k);这行代码时，实际上是将前一部分已经翻转的子链表（3->2->1）的最后一个节点（1）指向接下来要翻转的子链表的新头节点（6）
         * ，从而将这两部分正确地连接起来。这样，整个链表就变成了3->2->1->6->5->4。
        */
        head->next = reverse(next, k);
    }
    
    return prev; // 返回新的头节点
}

// 辅助函数：打印链表
void printList(struct ListNode *node) {
    while (node != NULL) {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");
}

int main() {
    // 创建链表
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    
    int k = 2; // 每k个节点翻转
    printf("原始链表: ");
    printList(head);
    
    // 翻转链表
    head = reverse(head, k);
    
    printf("翻转后链表: ");
    printList(head);
    
    return 0;
}
