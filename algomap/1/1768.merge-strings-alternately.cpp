/*
 * @lc app=leetcode id=1768 lang=cpp
 *
 * [1768] Merge Strings Alternately
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        int w1 = word1.size();
        int w2 = word2.size();
        int len = max(w1, w2);
        string s;
        int i = 0;
        int j = 0;
        while (len--)
        {
            if (i < w1 && j < w2)
            {
                s += word1[i];
                s += word2[j];
            }
            else if (i < w1 && j >= w2)
            {
                s += word1[i];
            }
            else if (i >= w1 && j < w2)
            {
                s += word2[j];
            }
            i++;
            j++;
        }
        return s;
    }
};
// @lc code=end
