/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> res;
    void dfs(int left,int right,string s,int n){
        if(s.size() == n*2) {
            res.push_back(s);
            return;
        }
        if(left < n) dfs(left+1,right,s+"(",n);
        if (right < left) dfs(left,right+1,s+")",n);
    }
    vector<string> generateParenthesis(int n) {
        dfs(0,0,"",n);
        return res;
    }
};
// @lc code=end

