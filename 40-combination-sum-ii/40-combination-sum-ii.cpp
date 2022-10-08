class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    void dfs(int idx, int sum, int target, vector<int>& cand) {
        if (idx >= cand.size() || sum >= target) {
            if (sum == target)
                res.push_back(cur);
            return;
        }
        for (int i = idx; i < cand.size(); i++) {
            if (i != idx && cand[i] == cand[i - 1])
                continue;
            cur.push_back(cand[i]);
            dfs(i + 1, sum + cand[i], target, cand);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(0, 0, target, candidates);
        return res;
    }
};