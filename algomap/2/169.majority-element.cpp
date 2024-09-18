/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        map<int, int> mp;
        for (auto n : nums)
        {
            mp[n]++;
        }
        int r = 0;
        for (auto m : mp)
        {
            if (m.second > nums.size() / 2)
            {
                return m.first;
            }
        }
        return 0;
    }
};
// @lc code=end
