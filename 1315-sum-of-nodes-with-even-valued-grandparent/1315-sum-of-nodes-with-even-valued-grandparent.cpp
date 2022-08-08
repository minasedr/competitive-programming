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
    int total = 0;
    int dfs(TreeNode* root, TreeNode* par, TreeNode* gpar) {
        if (!root)
            return 0;
        if (gpar && gpar->val % 2 == 0)
            total += root->val;
        dfs(root->left, root, par);
        dfs(root->right, root, par);
        return total;
    }
    int sumEvenGrandparent(TreeNode* root) {
       return dfs(root, NULL, NULL);
    }
};