#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution
{
public:
    int res = INT_MIN;
    int maxPathSum(TreeNode *root)
    {
        dfs(root);
        return res;
    };

private:
    int dfs(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);

        res = max(res, left + right + root->val);
        int Rmax = max(root->val + left, root->val + right);
        return Rmax < 0 ? 0 : Rmax;
    };
};