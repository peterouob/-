#include <bits/stdc++.h>

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int slow = 0, fast = 0;
        if (nums.size() == 0)
            return 0;
        while (fast < nums.size())
        {
            if (nums[fast] != nums[slow])
            {
                slow++;
                nums[slow] = nums[fast];
            }
            fast++;
        }
        return slow + 1;
    }
};