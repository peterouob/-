/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            int k = i;
            int j = i + 1;
            while (j < nums.size() && nums[k] + 1 == nums[j])
            {
                j++;
                k++;
            }
            if (i != k)
            {
                string s = to_string(nums[i]) + "->" + to_string(nums[k]);
                ans.push_back(s);
            }
            else
            {
                ans.push_back(to_string(nums[i]));
            }
            i = k;
        }
        return ans;
    }
};
// @lc code=end
