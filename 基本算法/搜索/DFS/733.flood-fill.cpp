/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int n, m, startColor = 0;
    void dfs(int x, int y, vector<vector<int>> &image, vector<vector<int>> &ans, int initColor, int newColor)
    {
        ans[x][y] = newColor;
        vector<pair<int, int>> dic = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1},
        };
        for (auto [dx, dy] : dic)
        {
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && image[nx][ny] == initColor && ans[nx][ny] != newColor)
            {
                dfs(nx, ny, image, ans, initColor, newColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        n = image.size();
        m = image[0].size();
        vector<vector<int>> &ans = image;
        int initColor = image[sr][sc];
        if (image[sr][sc] == initColor)
        {
            return image;
        }
        dfs(sr, sc, image, ans, initColor, color);
        return ans;
    }
};
// @lc code=end
