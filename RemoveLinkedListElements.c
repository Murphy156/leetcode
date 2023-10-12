/*
 * date ：2023/10/12
 * title：移除链表元素
 * brief：删除链表中等于给定值 val 的所有节点。
 * example：
 *          示例 1：输入：head = [1,2,6,3,4,5,6], val = 6 输出：[1,2,3,4,5]
 *          示例 2：输入：head = [], val = 1 输出：[]
 *          示例 3：输入：head = [7,7,7,7], val = 7 输出：[]
*/

/*
 *  思路： 
 *      1、直接使用原来的链表来进行删除操作。
 *      2、设置一个虚拟头结点在进行删除操作。
 * 
 * 
*/
#include <stdlib.h>
#include <stdio.h>

struct ListNode{
    int val; //节点上存储的元素
    struct ListNode *next; //指向下一个节点的指针
};

/* 定义链表节点指针类型 */
struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode* temp;
    /* 这里判断语句是判断首先head指针的地址值是否是NULL，第二就是判断它所指向的val值是否等于val */ 
    while(head && head->val == val) {
        temp = head;
        // 将新的头结点设置为head->next并删除原来的头结点
        head = head->next;
        free(temp);
    }
    struct ListNode *cur = head;
    // 当cur存在并且cur->next存在时
    // 此解法需要判断cur存在因为cur指向head。若head本身为NULL或者原链表中元素都为val的话，cur也会为NULL
    while(cur && (temp = cur->next)) {
        // 若cur->next的值等于val
        if(temp->val == val) {
            // 将cur->next设置为cur->next->next并删除cur->next
            cur->next = temp->next;
            free(temp);
        }
        // 若cur->next不等于val，则将cur后移一位
        else
            cur = cur->next;
    }
    // 返回头结点
    return head;
}

/* 设置一个虚拟头结点 */
struct ListNode* removeElementsVirtual(struct ListNode* head, int val){
    /*typedef struct ListNode ListNode; 的意思是将 struct ListNode 类型重命名为 ListNode，
    这样我们可以使用 ListNode 作为该类型的别名，而不需要每次都使用 struct ListNode。例如，我们可以这样声明一个变量：*/
    typedef struct ListNode ListNode;
    ListNode *shead;
    shead = (ListNode *)malloc(sizeof(ListNode));
    shead->next = head;
    ListNode *cur = shead;
    while(cur->next != NULL){
        if (cur->next->val == val){
            ListNode *tmp = cur->next;
            cur->next = cur->next->next;
            free(tmp);
        }
        else{
            cur = cur->next;
        }
    }
    head = shead->next;
    free(shead);
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

    int valToRemove = 6;
    struct ListNode* modifiedList = removeElementsVirtual(node1, valToRemove);

    printf("List after removing nodes with value %d:\n", valToRemove);
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