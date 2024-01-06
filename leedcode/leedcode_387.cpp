#include <iostream>
using namespace std;
#include <stack>
#include <string>
#include <string.h>


class Solution {
public:
    int firstUniqChar(string s) 
    {
        const char *ptr = s.c_str();
        const char *bakPtr = ptr;
        int bufFrequency[this->defaultVal];
        memset(bufFrequency, 0, sizeof(int) * this->defaultVal);

        int index = 0;
        while (*ptr != '\0')
        {
            index = *ptr - 97;
            bufFrequency[index]++;
            ptr++;
        }

        /* 指针回到字符串的开头位置 */
        ptr = bakPtr;
        int pos = 0;
        while (*ptr != '\0')
        {
            if (bufFrequency[*ptr - 97] == 1)
            {
                return pos;
            }
            pos++;
            ptr++;
        }
        return -1;
    }
private:
    const int defaultVal = 26;
};