#include <iostream>
using namespace std;
#include <stack>
#include <string>
#include <string.h>

class Solution {
public:
    bool isValid(string s) 
    {
        const char * ptr = s.c_str();
        std::stack<char> mystack;
        char topVal = '0';
        while (*ptr != '\0')
        {
            if (*ptr == '(' || *ptr == '[' || *ptr == '{')
            {
                mystack.push(*ptr);
            }
            else
            {
                /* 遍历到右括号，如果栈为空直接返回 */
                if (mystack.empty())
                {
                    return false;
                }
                /* 栈顶元素 */
                topVal = mystack.top();
                mystack.pop();
                if (*ptr == ')' && topVal != '(')
                {
                    return false;
                }
                else if (*ptr == ']' && topVal != '[')
                {
                    return false;
                }
                else if (*ptr == '}' && topVal != '{')
                {
                    return false;
                }
            }
            /* 指针后移 */
            ptr++;
        }
        if (mystack.empty())
        {
            return true;
        }
        return false;  
    }
};