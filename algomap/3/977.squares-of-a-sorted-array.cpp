/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        vector<int> vc;
        for (auto n : nums)
        {
            vc.push_back(pow(n, 2));
        }
        sort(vc.begin(), vc.end());
        return vc;
    }
};
// @lc code=end
