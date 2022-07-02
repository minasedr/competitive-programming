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
    vector<vector<int>>ans;
    void dfs(TreeNode* root, int target, vector<int> v) {
        if (!root)
            return;
        if (!root->left and !root->right and root->val == target){
            v.push_back(root->val);
            ans.push_back(v);
            return;
        }
        v.push_back(root->val);
        dfs(root->left, target-root->val, v);
        dfs(root->right, target-root->val, v);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> cur;
        dfs(root, targetSum, cur );
        return ans;
    }
};