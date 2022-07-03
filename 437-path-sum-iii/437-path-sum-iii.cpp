class Solution {
public:
    long long ans = 0;
    int pathSum(TreeNode* root, long long sum) {
        map<int, int> pref;
        pref[0] = 1;
        dfs(root, sum, 0, pref);
        return ans;
    }
    
    void dfs(TreeNode* root, long long sum, long long cur, map<int,int>pref) {
        if (!root)
            return;
        cur += root->val;
        ans += pref[cur- sum];
        pref[cur]++;
        dfs(root->left, sum , cur, pref);
        dfs(root->right, sum, cur, pref);
        pref[cur]--;
    }

};