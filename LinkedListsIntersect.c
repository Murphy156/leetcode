/*
 * date ：2023/10/21
 * title：链表相交
 * brief：给你两个单链表的头节点headA和headB，请你找出，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回NULL
 * example：
 *          input  : intersectVal = 8, listA = [4,1,8,4,5],listB = [5,0,1,8,4,5],skipA = 2,skipB = 3
 *          output : Intersected at '8'
*/


#include <stdlib.h>
#include <stdio.h>

typedef struct ListNode{
    int val;
    struct ListNode* next;
}ListNode;

ListNode *GetIntersectionNode(ListNode* headA,ListNode* headB){
    ListNode *l = NULL,*s = NULL;
    int lenA = 0,lenB = 0,gap = 0;

    /* 求出两个链表的长度 */
    s = headA;
    while (s)
    {
        lenA ++;
        s = s -> next;
    }
    s = headB;
    while (s)
    {
        lenB ++;
        s = s -> next;
    }

    /* 求出两个链表的长度差 */
    if(lenA > lenB){
        l = lenA, s = lenB;
        gap = lenA - lenB;
    }
    else{
        l = headB, s = headA;
        gap = lenB - lenA;
    }

    /* 尾部对齐 */
    while(gap--)l = l -> next;

    /* 移动，并检查是否有相同的元素 */
    while (l)
    {
        if(l == s) return l;
        l = l -> next;
        s = s -> next;
    }
    return NULL;
}

// 创建链表并返回指向头节点的指针
ListNode* createLinkedList(int data) {
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    head-> val = data;
    head-> next = NULL;
    return head;
}

// 打印链表的内容
void displayLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}


/* 在链表末尾添加新节点 */
void appendNode(ListNode* head, int data)
{
    ListNode* current = head;
    while (current->next != NULL)
    {
        current = current -> next;
    }
    
    ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
    new_node -> val = data;
    new_node -> next = NULL;
    current -> next = new_node;
}

int main() {
    ListNode* ListA = createLinkedList(4);
    ListNode* ListB = createLinkedList(5);

    /* 对链表进行添加元素 */
    appendNode(ListA, 1);
    appendNode(ListA, 8);
    appendNode(ListA, 4);
    appendNode(ListA, 5);

    appendNode(ListB, 0);
    appendNode(ListB, 1);
    appendNode(ListB, 8);
    appendNode(ListB, 4);
    appendNode(ListB, 5);

    // 测试移除指定值节点函数
    printf("Original ListA:\n");
    displayLinkedList(ListA);
    printf("Original ListB:\n");
    displayLinkedList(ListB);

    ListNode* ListC = GetIntersectionNode(ListA,ListB);

    printf("Exchange ListA:\n");
    displayLinkedList(ListC);

    return 0;
}

