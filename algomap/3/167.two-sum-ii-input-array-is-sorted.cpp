/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int start = 0;
        int end = numbers.size() - 1;
        while (start <= end)
        {
            int t = numbers[start] + numbers[end];
            if (t == target)
            {
                return {start + 1, end + 1};
            }
            else if (t > target)
            {
                end--;
            }
            else
            {
                start++;
            }
        }
        return {};
    }
};
// @lc code=end
