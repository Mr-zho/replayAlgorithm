#include <iostream>
using namespace std;
#include <stack>
#include <string>
#include <string.h>



// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) 
    {
        if (head == NULL)
        {
            return true;
        }

        stack<ListNode*> mystack;

        ListNode* travelNode = head;

        while (travelNode != NULL)
        {
            mystack.push(travelNode);
            travelNode = travelNode->next;
        }
        travelNode = head;

        ListNode* topVal = NULL;
        while (!mystack.empty())
        {
            topVal = mystack.top();
            mystack.pop();

            if (travelNode->val != topVal->val)
            {
                return false;
            }
            travelNode = travelNode->next;
        }
        return true;
    }
};
