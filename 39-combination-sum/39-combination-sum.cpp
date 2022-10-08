class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    set<set<int>> vis;
    
    void dfs(int idx, int sum, int target, vector<int>& cand) {
        if (sum >= target || idx >= cand.size()) {
            set<int> st(cur.begin(),cur.end());
            if (sum == target && !vis.count(st))
                res.push_back(cur);
            return;
        }
        for (int i = idx; i < cand.size(); i++) {
            cur.push_back(cand[i]);
            dfs(i, sum + cand[i], target, cand);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(0, 0, target, candidates);
        return res;
    }
};