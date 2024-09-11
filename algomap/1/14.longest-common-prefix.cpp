/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        sort(strs.begin(), strs.end());
        string s1 = strs[0];
        string s2 = strs[strs.size() - 1];
        int n = s1.size();
        string r;
        for(int i=0;i<n;i++){
            if(s1[i] == s2[i]){
                r += s1[i];
            }else{
                break;
            }
        }
        return r;
    }
};
// @lc code=end
