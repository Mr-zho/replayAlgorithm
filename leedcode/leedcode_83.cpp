#include <iostream>
using namespace std;
#include <stack>
#include <string>
#include <string.h>



/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode * prev = head;
        ListNode * travel = head->next;
        
        while (travel != NULL)
        {
            if (prev->val == travel->val)
            {
                travel = travel->next;
            }
            else
            {
                prev->next = travel;
                prev = travel;
                travel = travel->next;
            }
        }
        prev->next = travel;
        return head;
    }
};