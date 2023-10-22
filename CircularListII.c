/*
 * date ：2023/10/22
 * title：环形链表II
 * brief：给定一个链表，返回链表开始入环的第一个节点，如果链表无环，则返沪NULL
 *        为了表示给定链表中的环，使用整数pos来表示链表尾连接到链表中的位置（索引从0开始）。如果pos是-1，则在该链表中没有环
 * example：
 *          input  : head = [3，2，0，-4]， pos = 1; 
 *          output : tail connects to node index 1; 
*/

#include <stdlib.h>
#include <stdio.h>

/** typedef的用法是定义最后的那个ListNode */
/** struct 是定义第一个那个ListNode */
typedef struct ListNode{
    int val;
    struct ListNode* next;
}ListNode;

ListNode* detectCycle(ListNode* head)
{
    ListNode *fast = head, *slow = head;
    while (fast && fast->next)
    {
        /* 这里判断两个指针是否相等，所以移位操作放在前面 */
        slow = slow->next;
        fast = fast->next->next;
    
        if(slow == fast){
            ListNode *f = fast,*h = head;
            while (f != h) f = f->next , h->next; 
            return h;
        }
    }

    return NULL;
}