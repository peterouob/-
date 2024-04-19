#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        if (nums.size() == 1)
            return true;
        // 每次走的最大步數能>size -> true : false
        int count = 0;
        // 最多能走的步數會是最大的步數，如果是 < nums.size()根本不會記算能走步數
        for (int i = 0; i <= count; i++)
        {
            count = max(i + nums[i], count);
            if (count >= nums.size())
                return true;
        }
        return false;
    }
};