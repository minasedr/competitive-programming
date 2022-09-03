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
    int good(TreeNode* root, int parent) {
        if (not root)
            return 0;
        if (root->val >= parent)
            return 1 + good(root->left, root->val) + good(root->right, root->val);
        return good(root->left, parent) + good(root->right, parent);
    }
    int goodNodes(TreeNode* root) {
        return good(root, INT_MIN);
    }
};