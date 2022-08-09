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
    pair<TreeNode*,int> dfs(TreeNode* root, int d) {
        if (!root)
            return {NULL, d - 1};
        if (!root->left && !root->right)
            return {root, d};
        auto left = dfs(root->left, d + 1);
        auto right = dfs(root->right, d + 1);
        if (left.second == right.second)
            return {root, left.second};
        else if (left.second < right.second)
            return right;
        else
            return left;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root, 0).first;
    }
};