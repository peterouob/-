/*
 * @lc app=leetcode id=1189 lang=cpp
 *
 * [1189] Maximum Number of Balloons
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        if (text.size() < 7)
            return 0;
        int r[26];
        memset(r, 26, 0);
        int n = INT_MAX;
        for (int i = 0; i < text.size(); i++)
        {
            r[text[i] - 'a']++;
        }
        n = min(r[0], n); //a 0
        n = min(r[1], n); //b 1
        n = min(r[11] / 2, n); // l 
        n = min(r[14] / 2, n); // o
        n = min(r[13], n); // n
        return n;
    }
};
// @lc code=end
