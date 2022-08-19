class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> dp(int idx, int cur, int tar, vector<int> app, vector<int>& cand) {
        if (idx >= cand.size() || cur >= tar) {
            if (cur == tar)
                res.push_back(app);
            return {};
        }
        for (int i = idx; i < cand.size(); i++) {
            app.push_back(cand[i]);
            dp(i, cur + cand[i], tar, app, cand);
            app.pop_back();
        }
        return res;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>cur;
        return dp(0, 0, target, cur, candidates);
    }
};