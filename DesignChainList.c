/*
 * date ：2023/10/14
 * title：设计链表
 * brief：在链表类中实现这些功能：
 * example：
 *          get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
 *          addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
 *          addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
 *          addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。
 *                                 如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
 *          deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct MyLinkedList {
    int val;
    struct MyLinkedList* next;
}MyLinkedList;

/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate() {
    //这个题必须用虚拟头指针,参数都是一级指针,头节点确定后没法改指向了!!!
    MyLinkedList* head = (MyLinkedList *)malloc(sizeof (MyLinkedList));
    head->next = NULL;
    return head;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    MyLinkedList *cur = obj->next;
    for (int i = 0; cur != NULL; i++){
        if (i == index){
            return cur->val;
        }
        else{
            cur = cur->next;
        }
    }
    return -1;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList *nhead = (MyLinkedList *)malloc(sizeof (MyLinkedList));
    nhead->val = val;
    nhead->next = obj->next;
    obj->next = nhead;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList *cur = obj;
    while(cur->next != NULL){
        cur = cur->next;
    }
    MyLinkedList *ntail = (MyLinkedList *)malloc(sizeof (MyLinkedList));
    ntail->val = val;
    ntail->next = NULL;
    cur->next = ntail;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index == 0){
        myLinkedListAddAtHead(obj, val);
        return;
    }
    MyLinkedList *cur = obj->next;
    for (int i = 1 ;cur != NULL; i++){
        if (i == index){
            MyLinkedList* newnode = (MyLinkedList *)malloc(sizeof (MyLinkedList));
            newnode->val = val;
            newnode->next = cur->next;
            cur->next = newnode;
            return;
        }
        else{
            cur = cur->next;
        }
    }
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index == 0){
        MyLinkedList *tmp = obj->next;
        if (tmp != NULL){
            obj->next = tmp->next;
            free(tmp);     
        }
        return;
    }
    MyLinkedList *cur = obj->next;
    for (int i = 1 ;cur != NULL && cur->next != NULL; i++){
        if (i == index){
            MyLinkedList *tmp = cur->next;
            if (tmp != NULL) {
                cur->next = tmp->next;
                free(tmp);
            }
            return;
        }
        else{
            cur = cur->next;
        }
    }
    
}

void myLinkedListFree(MyLinkedList* obj) {
    while(obj != NULL){
        MyLinkedList *tmp = obj;
        obj = obj->next;
        free(tmp);
    }
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/