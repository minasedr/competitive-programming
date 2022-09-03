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
        queue<TreeNode*> q;
        vector<double> res;
        q.push(root);
        
        while (!q.empty()) {
            int n = q.size();
            double cur = 0;
            
            for (int i = 0; i  < n; i++) {
                auto u = q.front();
                cur += u->val;
                
                if (u->left)
                    q.push(u->left);
                
                if (u->right)
                    q.push(u->right);
                q.pop();
            }
            res.push_back(cur / n);
        }
        return res;
    }
};