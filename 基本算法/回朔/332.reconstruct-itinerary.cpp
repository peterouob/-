/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    unordered_map<string, map<string, int>> targets;
    bool backtrack(int times, vector<string> &result)
    {
        if (result.size() == times + 1)
        {
            return true;
        }
        for (pair<const string, int> &target : targets[result[result.size() - 1]])
        {
            if (target.second > 0)
            {
                result.push_back(target.first);
                target.second--;
                if (backtrack(times, result))
                    return true;
                result.pop_back();
                target.second++;
            }
        }
        return false;
    }
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        targets.clear();
        vector<string>
            result;
        for (const vector<string> &vc : tickets)
        {
            targets[vc[0]][vc[1]]++;
        }
        result.push_back("JFK");
        backtrack(tickets.size(), result);
        return result;
    }
};
// @lc code=end
