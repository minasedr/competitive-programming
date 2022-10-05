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
    void dfs(TreeNode* root, int cur, int val, int depth) {
        if (not root)
            return;
        if (cur == depth - 1) {
            TreeNode* tmp = root->left;
            root->left = new TreeNode(val);
            root->left->left = tmp;
            tmp = root->right;
            root->right = new TreeNode(val);
            root->right->right = tmp;
        }
        dfs(root->left, cur + 1, val, depth);
        dfs(root->right, cur + 1, val, depth);
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        } 
        dfs(root, 1, val, depth);
        return root;
    }
};