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
    int res = INT_MIN;
    int dfs(TreeNode* root) {
        if (root == NULL)
            return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        int cur = root->val + max({left, right, 0});
        res = max({res, cur, left + right + root->val});

        return cur;
    }
    
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
};