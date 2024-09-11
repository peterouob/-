/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int b = INT_MAX;
        int s = 0;
        for (auto n : prices)
        {
            b = min(b, n);
            s = max(s, n - b);
        }
        return s;
    }
};
// @lc code=end
