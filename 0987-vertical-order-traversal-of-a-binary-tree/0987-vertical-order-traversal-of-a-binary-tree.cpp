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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int,int>>> store;
        
        function<void(TreeNode*, int, int)> dfs;
        dfs = [&](TreeNode* cur, int row, int col) {
            if (not cur)
                return;
            dfs(cur->left, row + 1, col - 1);
            dfs(cur->right, row + 1, col + 1);
            store[col].push_back({row, cur->val});
        };
        
        dfs(root, 0, 0);
        vector<vector<int>> ans;
        
        for (auto &[col, els]: store) {
            sort(els.begin(), els.end());
            vector<int> cur;
            for (auto el: els)
                cur.push_back(el.second);
            ans.push_back(cur);
        }
        
        return ans;
    }
};