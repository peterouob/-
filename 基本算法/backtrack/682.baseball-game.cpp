/*
 * @lc app=leetcode id=682 lang=cpp
 *
 * [682] Baseball Game
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int calPoints(vector<string> &operations)
    {
        stack<int> st;
        for (auto n : operations)
        {
            if (n == "+")
            {
                int top = st.top();
                st.pop();
                int val = top + st.top();
                st.push(top);
                st.push(val);
            }
            else if (n == "D")
            {
                st.push(2 * st.top());
            }
            else if (n == "C")
            {
                st.pop();
            }
            else
            {
                st.push(stoi(n));
            }
        }
        int v = 0;
        while (!st.empty())
        {
            v += st.top();
            st.pop();
        }
        return v;
    }
};
// @lc code=end
