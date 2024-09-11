/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
             { return a[0] < b[0]; });

        vector<vector<int>> megred;
        vector<int> prev = intervals[0];
        for (int i = 1; i < intervals.size(); i++)
        {
            vector<int> interval = intervals[i];
            if (interval[0] <= prev[1])
            {
                prev[1] = max(prev[1], interval[1]);
            }
            else
            {
                megred.push_back(prev);
                prev = interval;
            }
        }
        megred.push_back(prev);
        return megred;
    }
};
// @lc code=end
