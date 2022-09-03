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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (not root)
            return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int n = q.size();
            vector<int>cur;
            for (int i = 0; i < n; i++) {
                auto u = q.front();
                if (u->left)
                    q.push(u->left);
                if (u->right)
                    q.push(u->right);
                cur.push_back(u->val);
                q.pop();
            }
            res.push_back(cur);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};