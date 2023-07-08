#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int num = 0;
    int totalNQueens(int n)
    {
        vector<string> borad(n, string(n, '.'));
        backtrack(borad, 0);
        return num;
    }

    void backtrack(vector<string> borad, int row)
    {
        if (row == borad.size())
        {
            num++;
            return;
        }
        int n = borad[row].size();
        for (int col = 0; col < n; col++)
        {
            if (!isVaild(borad, row, col))
            {
                continue;
            }
            borad[row][col] = 'Q';
            backtrack(borad, row + 1);
            borad[row][col] = '.';
        }
    }

    bool isVaild(vector<string> borad, int row, int col)
    {
        int n = borad.size();
        for (int i = 0; i < n; i++)
        {
            if (borad[i][col] == 'Q')
            {
                return false;
            }
        }

        for (int i = row - 1, j = col + 1; i >= 0 && j <= n; i--, j++)
        {
            if (borad[i][j] == 'Q')
            {
                return false;
            }
        }

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (borad[i][j] == 'Q')
            {
                return false;
            }
        }
        return true;
    }
};