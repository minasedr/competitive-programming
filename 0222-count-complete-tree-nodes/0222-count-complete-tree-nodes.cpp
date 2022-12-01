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
    int ans = 0;
    int dfs(TreeNode* root) {
        if (not root)
            return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        ans = max(ans, left + right + 1);
        return (left + right + 1);
    }
    int countNodes(TreeNode* root) {
        dfs(root);
        return ans;
    }
};