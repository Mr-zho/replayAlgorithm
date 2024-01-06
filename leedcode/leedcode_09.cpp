#include <iostream>
using namespace std;
#include <stack>
#include <string>
#include <string.h>
#include <vector>


class Solution {
public:
    bool isPalindrome(int x) 
    {
        vector<int> myvec;
        if (x < 0)
        {
            return false;
        }

        int tmp = x;
        while (tmp)
        {
            myvec.push_back(tmp % 10);
            tmp /= 10;
        }

        int begin = 0;
        int end = myvec.size() - 1;

        while (begin < end)
        {
            if (myvec[begin++] != myvec[end--])
            {
                return false;
            }
        }
        return true;
    }
};