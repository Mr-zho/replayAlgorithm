#include <iostream>
using namespace std;


class Solution {
public:
    string removeDuplicates(string s) 
    {
        const char *ptr = s.c_str();
        stack<char> mystack;
        char topval = '0';
        /* 用来存放返回的字符串 */
        std :: string myString;
        myString = "";
        /*先将第一个元素入栈 */
        mystack.push(*ptr);
        ptr++;
        while (*ptr != '\0')
        {
            /* 如果栈为空*/
            if (mystack.empty())
            {
                /* 直接将字符入栈 */
                mystack.push(*ptr);
            }
            /* 如果栈不为空，就需要对比字符相不相等 */
            else
            {
                /* 拿到栈顶元素 */
                topval = mystack.top();
                if (*ptr == topval)
                {
                    mystack.pop();
                }
                else
                {
                    mystack.push(*ptr);
                }
            }
            ptr++;
        }
        /* 此时栈如果不为空，那就是剩下的不重复的字符 */
        while (!mystack.empty())
        {
            topval = mystack.top();
            mystack.pop();
            myString += topval;
        }
        /* 反转. */
        /* 此时拿到的是倒的字符，进行反转 */
        int begin = 0, end = myString.size() - 1;
        while (begin < end)
        {
            swap(myString[end--], myString[begin++]);
        }
        return myString;
    }
};


int main()
{


    return 0;
}