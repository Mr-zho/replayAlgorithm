#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
#include <string>

class Solution {
public:
    static bool repeatedSubstringPattern(string s) 
    {
        const char *ptr = s.c_str();
        int length = s.size();
        /* 定义窗口的大小 窗口的最小值从1开始 */
        for (int window = 1; window <= length >> 1; window++)
        {
            int flag = 0;
            char ptrWin[window + 1];
            memset(ptrWin, 0, sizeof(ptrWin));

            int idx = 0;
            for (idx; idx < window; idx++)
            {
                ptrWin[idx] = *(ptr+idx);
            }  
            ptrWin[idx] = '\0';

            for (int jdx = window; jdx < length; jdx += window)
            {
                /* 窗口 比较 字符串 */
                int cmp = strncmp(ptrWin, ptr + jdx, window);
                if (cmp == 0)
                {
                    continue;
                }
                else
                {
                    flag = 1;
                    break;
                }
            }

            if (flag == 0)
            {
                return true;
            } 
        }
        return false;
    }
};


class Solution1 {
public:
    bool repeatedSubstringPattern(string s) 
    {
        const char *ptr = s.c_str();
        int length = s.size();
        int flag = 0;

        /* 定义窗口的大小 窗口的最小值从1开始 */
        for (int window = 1; window <= length >> 1; window++)
        {
            /* 如果window不满足被字符串整除, 此窗口大小不满足, 需要更换窗口大小 */
            if (length % window != 0)
            {
                continue;
            }
            
            flag = 0;
            char ptrWin[window + 1];
            memset(ptrWin, 0, sizeof(ptrWin));
            for (int idx = 0; idx < window; idx++)
            {
                ptrWin[idx] = *(ptr+idx);
            }  

            for (int jdx = window; jdx < length; jdx += window)
            {
                if (strncmp(ptrWin, ptr + jdx, window) != 0)
                {
                    flag = 1;
                    break;
                }
            }

            if (flag == 0)
            {
                return true;
            } 
        }
        return false;
    }
};

int main()
{
    string str = "abababa";
    bool res = Solution::repeatedSubstringPattern(str);

    printf("res:%d\n", res);

    return 0;
}