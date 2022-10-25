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
    pair<int, int> dfs(TreeNode* node) {
        if (not node)
            return {0, 0};
        
        auto [leftRob, leftDont] = dfs(node->left);
        auto [rightRob, rightDont] = dfs(node->right);
        int robNow = leftDont + rightDont;
        int dontNow = max({robNow, leftDont + rightRob, leftRob + rightDont, rightRob + leftRob});
        return {node->val + robNow, dontNow};
    }
    int rob(TreeNode* root) {
        auto ans = dfs(root);
        return max(ans.first, ans.second);
    }
};