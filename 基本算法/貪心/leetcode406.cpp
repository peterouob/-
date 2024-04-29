#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        vector<vector<int>> que;
        sort(people.begin(), people.end(), cmp);
        for (int i = 0; i < people.size(); i++)
        {
            int postion = people[i][1];
            que.insert(que.begin() + postion, people[i]);
        }
        return que;
    }
};