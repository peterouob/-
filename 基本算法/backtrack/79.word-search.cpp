/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int rows = 0;
    int cols = 0;
    bool dfs(vector<vector<char>>&board,string word,int row,int col,int index){
        if(index == word.size()) return true;
        if(row < 0 || row >= rows || col < 0 || col >= cols || board[row][col] != word[index]) return false;
        vector<pair<int,int>> dict = 
        {
            {0,1},
            {0,-1},
            {1,0},
            {-1,0}
        };
        char tmp = board[row][col];
        board[row][col] = '*';
        for(auto [dx,dy] : dict) {
            int x = row + dx;
            int y = col + dy;
            if(dfs(board,word,x,y,index+1))return true;
        }
        board[row][col] = tmp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        rows = board.size();
        cols = board[0].size();
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(dfs(board,word,i,j,0)) return true;
            }
        }
        return false;
    }
};
// @lc code=end

