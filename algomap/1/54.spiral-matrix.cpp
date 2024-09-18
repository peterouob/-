/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    vector<int> result;
    int n, m = 0;

    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        n = matrix.size();
        m = matrix[0].size();
        int top = 0, bottom = n - 1;
        int left = 0, right = m - 1;
        vector<int> v;
        while (top <= bottom && left <= right)
        {
            for (int i = left; i <= right; i++)
            {
                v.push_back(matrix[top][i]);
            }
            top++;
            for (int i = top; i <= bottom; i++)
            {
                v.push_back(matrix[i][right]);
            }
            right--;
            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                {
                    v.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                {
                    v.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return v;
    }
};
// @lc code=end
