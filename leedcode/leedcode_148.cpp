#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* sortList(struct ListNode* head) 
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    struct ListNode * travel = head;
    while (travel != NULL)
    {
        struct ListNode * prev = head;
        struct ListNode * begin = head->next;

        for (; begin != NULL; begin = begin->next)
        {
            /* 后一个数 比前一个数😊 */
            if (begin->val < prev->val)
            {
                /* 交换元素 */
                int tmpval = begin->val;
                begin->val = prev->val;
                prev->val = tmpval;
            }
            prev = prev->next;
        }

        /* 轮数 */
        travel = travel->next;
    }  
    return head;
}   