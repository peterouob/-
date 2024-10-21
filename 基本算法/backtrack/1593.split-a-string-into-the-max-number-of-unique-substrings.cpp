/*
 * @lc app=leetcode id=1593 lang=cpp
 *
 * [1593] Split a String Into the Max Number of Unique Substrings
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int backtrack(int start,string &s,unordered_set<string>&us){
        if(start == s.size()){
            return 0;
        }
        int maxSpilte = 0;
        for(int r=start+1;r <= s.size();r++){
            string sub = s.substr(start,r-start);
            if(us.find(sub) == us.end()){
                us.insert(sub);
                maxSpilte = max(maxSpilte,1+backtrack(r,s,us));
                us.erase(sub);
            }
        }
        return maxSpilte;
    }
    int maxUniqueSplit(string s) {
        unordered_set<string> us;
        return backtrack(0,s,us);
    }
};
// @lc code=end

