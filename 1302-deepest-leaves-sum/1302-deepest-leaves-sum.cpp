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
    int deepestLeavesSum(TreeNode* root) {
        int level = 1, mx = root->val;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int n = q.size();
            int cur = 0;
            for (int i = 0; i < n; i++) {
                auto u = q.front();
                if (u->left)
                    q.push(u->left);
                if (u->right)
                    q.push(u->right);
                cur += u->val;
                q.pop();
            }
            mx = cur;
        }
        return mx;
    }
};