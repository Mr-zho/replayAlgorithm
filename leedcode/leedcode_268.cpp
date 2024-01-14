#include <iostream>
using namespace std;
#include <stack>
#include <string>
#include <string.h>
#include <vector>
#include <set>

class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        set<int> myset;

        for (int idx = 0; idx < nums.size(); idx++)
        {
            myset.insert(nums.at(idx));
        }

        int idx = 0;
        for (idx; idx <= nums.size(); idx++)
        {
            if (myset.count(idx) == 0)
            {
                break;  
            }
        }
        return idx;
    }
};

