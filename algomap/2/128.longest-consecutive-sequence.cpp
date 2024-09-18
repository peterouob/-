/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;
        for (auto n : nums)
        {
            if (!s.count(n-1)){
                int length = 1;
                while(s.count(n + length)){
                    length++;
                }
                longest = max(longest,length);
            }
        }
        return longest;
    }
};
// @lc code=end
