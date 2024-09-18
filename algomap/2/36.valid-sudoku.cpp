/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxs[9];
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;
                int boxIndex = (i / 3) * 3 + j / 3;
                /*
                9*9 -> 3*3
                [0,0] [0,3] [0,6] / 3
                [3,0] [3,3] [3,6] / 3
                [6,0] [6,3] [6,6] / 3
                 */
                if (rows[i].count(board[i][j]) || cols[j].count(board[i][j]) || boxs[boxIndex].count(board[i][j]))
                {
                    return false;
                }
                rows[i].insert(board[i][j]);
                cols[j].insert(board[i][j]);
                boxs[boxIndex].insert(board[i][j]);
            }
        }
        return true;
    }
};
// @lc code=end
