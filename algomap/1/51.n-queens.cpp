/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<string>> result;
    bool isVaild(int row, int col, vector<string> &board, int n)
    {
        for (int i = 0; i < row; i++)
        {
            if (board[i][col] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }
    void backtrack(int n, int row, vector<string> &board)
    {
        if (row == n)
        {
            result.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++)
        {
            if (isVaild(row, col, board, n))
            {
                board[row][col] = 'Q';
                backtrack(n, row + 1, board);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board(n, string(n, '.'));
        backtrack(n, 0, board);
        return result;
    }
};
// @lc code=end
