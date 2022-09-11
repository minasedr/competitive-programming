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
    int diameter = 0;
    int dfs(TreeNode* root) {
        if (not root)
            return -1;
        if (not root->left and not root->right)
            return 0;
        
        int left = 1 + dfs(root->left);
        int right = 1 + dfs(root->right);
        diameter = max(diameter, left + right);
        return max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return diameter;
    }
};