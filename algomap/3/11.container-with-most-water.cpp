/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int m = 0;
        int l = 0;
        int r = height.size() - 1;
        while (l < r)
        {
            m = max(m, (r - l) * min(height[r], height[l]));
            if (height[r] > height[l])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return m;
    }
};
// @lc code=end
