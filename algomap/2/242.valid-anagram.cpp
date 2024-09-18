/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (t.size() > s.size())
            return false;
        map<char, int> mp;
        mp.clear();
        for (auto v : s)
        {
            mp[v]++;
        }
        for (auto v : t)
        {
            mp[v]--;
        }

        for(auto m : mp){
            if(m.second > 0) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
