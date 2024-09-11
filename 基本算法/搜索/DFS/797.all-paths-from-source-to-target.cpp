/*
 * @lc app=leetcode id=797 lang=cpp
 *
 * [797] All Paths From Source to Target
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    vector<vector<int>> result;
    vector<int> path;
    int n = 0;
    void dfs(vector<vector<int>> &graph, int i)
    {
        if (i == n - 1)
        {
            result.push_back(path);
            return;
        }
        for (int it : graph[i])
        {
            path.push_back(it);
            dfs(graph, it);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        n = graph.size();
        path.push_back(0);
        dfs(graph, 0);
        return result;
    }
};
// @lc code=end
