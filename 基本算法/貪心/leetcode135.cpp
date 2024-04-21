#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        vector<int> candyVec(ratings.size(), 1);
        // 從左向右
        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] > ratings[i - 1])
                candyVec[i] = candyVec[i - 1] + 1;
        }
        // 從右向左
        for (int i = ratings.size() - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
                candyVec[i] = max(candyVec[i], candyVec[i] + 1);
        }
        int sum = 0;
        for (int c : candyVec)
        {
            sum += c;
        }
        return sum;
    }
};