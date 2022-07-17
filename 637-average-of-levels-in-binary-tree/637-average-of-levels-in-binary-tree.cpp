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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<double>ans;
        long long cur = 0;
        while (!q.empty()) {
            int n = q.size();
            cur = 0;
            for (int i = 0; i < n; i++) {
                auto u = q.front();
                q.pop();
                cur += u->val;
                if (u->left)
                    q.push(u->left);
                if (u->right)
                    q.push(u->right);
            }
            ans.push_back(double(cur)/n);
        }
        return ans;
    }
};