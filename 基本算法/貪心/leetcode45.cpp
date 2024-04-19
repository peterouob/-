#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        if (nums.size() - 1 <= 0)
            return 0;
        int cur = 0;
        int next = 0;
        int result = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            // 下一次能走的最遠距離
            next = max(i + nums[i], next);
            // 能走到的最遠下標
            if (i == cur)
            {
                cur = next;
                result++;
                if (cur >= nums.size() - 1)
                {
                    break;
                }
            }
        }
        return result;
    }
};