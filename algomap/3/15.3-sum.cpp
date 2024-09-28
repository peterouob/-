/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int slow = i + 1;
            int fast = nums.size() - 1;
            while (slow < fast)
            {
                int total = nums[i] + nums[slow] + nums[fast];
                if (total > 0)
                {
                    fast--;
                }
                else if (total < 0)
                {
                    slow++;
                }
                else
                {
                    res.push_back({nums[i], nums[slow], nums[fast]});
                    slow++;
                    while (nums[slow] == nums[slow - 1] && slow < fast)
                    {
                        slow++;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
