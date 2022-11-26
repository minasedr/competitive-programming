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
    int ans = INT_MIN;
    int dfs(TreeNode* root) {
        if (not root)
            return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        ans = max({ans, root->val, left + root->val, right + root->val, left + right + root->val});
        return max({left, right, 0}) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};