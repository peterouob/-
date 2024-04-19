#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums.size();
        int result = 1; // 默認最有有峰值
        int preDiff = 0;
        int curDiff = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            curDiff = nums[i] - nums[i + 1];
            if ((preDiff >= 0 && curDiff < 0) || (preDiff <= 0 && curDiff > 0))
            {
                result++;
                preDiff = curDiff;
            }
        }
        return result;
    }
};