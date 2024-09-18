/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int r[26];
        memset(r, 0, 26);
        if (ransomNote.size() > magazine.size())
        {
            return false;
        }
        for (int i = 0; i < magazine.size(); i++)
        {
            r[magazine[i] - 'a']++;
        }
        for (int i = 0; i < ransomNote.size(); i++)
        {
            r[ransomNote[i] - 'a']--;
            if (r[ransomNote[i] - 'a'] < 0)
                return false;
        }
        return true;
    }
};
// @lc code=end
