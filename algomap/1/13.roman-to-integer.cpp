/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int romanToInt(string s)
    {
        int result = 0;
        map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        for (int i = 0; i < s.size(); i++)
        {
            if (mp[s[i]] < mp[s[i + 1]])
            {
                result -= mp[s[i]];
            }
            else
            {
                result += mp[s[i]];
            }
        }
        return result;
    }
};
// @lc code=end
