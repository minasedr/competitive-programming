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
    vector<int> diff;
    void dfs(TreeNode* root) {
        if (not root)
            return;
        dfs(root->left);
        diff.push_back(root->val);
        dfs(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        int ans = INT_MAX, n = diff.size();
        for (int i = 1; i < n; i++)
            ans = min(ans, diff[i] - diff[i - 1]);
        
        return ans;
    }
};