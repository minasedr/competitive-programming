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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool rev = false;
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        if (!root) return {};
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> row;
            for (int i = 0; i < n; i++) {
                auto u = q.front();
                q.pop();
                row.push_back(u->val);
                if (u->left)
                    q.push(u->left);
                if (u->right)
                    q.push(u->right);
            }
            if (rev)
                reverse(row.begin(),row.end());
            rev = !rev;
            ans.push_back(row);
        }
        return ans;
    }
};