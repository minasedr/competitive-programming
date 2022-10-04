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
    unordered_map<long, int> cnt{{0, 1}};
    long ans = 0;
    
    void dfs(TreeNode* root, long cur, int target) {
        if (not root)
            return;
        cur += root->val;
        ans += cnt[cur - target];
        cnt[cur]++;
        dfs(root->left, cur, target);
        dfs(root->right, cur, target);
        cnt[cur]--;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        dfs(root, 0, targetSum);
        return ans;
    }
};