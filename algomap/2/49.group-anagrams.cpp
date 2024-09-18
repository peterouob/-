/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        mp.clear();
        for (auto s : strs)
        {
            auto word = s;
            sort(word.begin(), word.end());
            mp[word].push_back(s);
        }
        vector<vector<string>> r;
        for(auto m : mp){
            r.push_back(m.second);
        }
        return r;
    }
};
// @lc code=end
