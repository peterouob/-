/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int count;

    void bfs(vector<vector<int>> &grid, int r, int c, int rows, int cols)
    {
        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = 0;
        count++;

        vector<pair<int, int>> dic = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1},
        };
        while (!q.empty())
        {
            auto [row, col] = q.front();
            q.pop();
            for (auto [dr, dc] : dic)
            {
                int nr = row + dr;
                int nc = col + dc;
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1)
                {
                    count++;
                    q.push({nr, nc});
                    grid[nr][nc] = 0;
                }
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    count = 0;
                    bfs(grid, i, j, n, m);
                    result = max(result, count);
                }
            }
        }
        return result;
    }
};
// @lc code=end
