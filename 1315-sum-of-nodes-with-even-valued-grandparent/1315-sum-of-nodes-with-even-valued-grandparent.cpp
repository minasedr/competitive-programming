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
    int sum(TreeNode* root) {
        int ans = 0;
        if (!root)
            return 0;
        if (root->left)
            ans += root->left->val;
        if (root->right)
            ans += root->right->val;
        return ans;
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        int total = 0;
        function<int(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root)
                return 0;
            if (root->val % 2 == 0)
                total += sum(root->left) + sum(root->right);
            dfs(root->left);
            dfs(root->right);
            return total;
                
        };
        return dfs(root);
    }
};