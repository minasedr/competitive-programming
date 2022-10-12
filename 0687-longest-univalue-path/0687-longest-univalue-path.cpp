/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res = 0;
    pair<int, int> dfs(TreeNode* root) {
        if (not root)
            return {1e4, 0};
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        int L = 0, R = 0;
        if (left.first == root->val)
            L = left.second + 1;
        if (right.first == root->val)
            R = right.second + 1;
        res = max(res, L + R);
        return {root->val, max(L, R)};
    }
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return res;
    }
};