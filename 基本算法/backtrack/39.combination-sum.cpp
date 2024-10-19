/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void dfs(vector<int>& candidates,int target,int sum,int start){
        if(sum == target) {
            result.push_back(path);
            return;
        }
        for(int i=start;i<candidates.size() && sum + candidates[i] <= target;i++){
            sum += candidates[i];
            path.push_back(candidates[i]);
            dfs(candidates,target,sum,i);
            sum -= candidates[i];
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int sum = 0;
        sort(candidates.begin(),candidates.end());
        dfs(candidates,target,sum,0);
        return result;
    }
};
// @lc code=end

