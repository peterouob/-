#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int start = 0;
        int totlaSum = 0;
        int curSum = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            totlaSum += gas[i] - cost[i];
            curSum += gas[i] - cost[i];
            if (curSum < 0)
            {
                start = i + 1;
                curSum = 0;
            }
        }
        if (totlaSum < 0)
            return -1;
        return start;
    }
};