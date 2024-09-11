/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    class MyQueue
    {
    public:
        deque<int> dq;
        void pop(int val)
        {
            if (!dq.empty() && dq.front() == val)
                dq.pop_front();
        }
        void push(int val)
        {
            while (!dq.empty() && dq.back() < val)
                dq.pop_back();
            dq.push_back(val);
        }
        int front()
        {
            return dq.front();
        }
    };

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        MyQueue q;
        vector<int> result;
        for (int i = 0; i < k; i++)
        {
            q.push(nums[i]);
        }
        result.push_back(q.front());
        for (int i = k; i < nums.size(); i++)
        {
            q.pop(nums[i - k]);
            q.push(nums[i]);
            result.push_back(q.front());
        }
        return result;
    }
};
// @lc code=end
