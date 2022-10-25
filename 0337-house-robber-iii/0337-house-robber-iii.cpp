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
    pair<int, int> dfs(TreeNode* node) {
        if (not node)
            return {0, 0};
        auto left = dfs(node->left);
        auto right = dfs(node->right);
        int x = left.first + right.first;
        int y = left.second + right.second;
        int a = left.first + right.second;
        int b = left.second + right.first;
        return {y + node->val, max({x,y,a,b})};
    }
    int rob(TreeNode* root) {
        auto ans = dfs(root);
        return max(ans.first, ans.second);
    }
};