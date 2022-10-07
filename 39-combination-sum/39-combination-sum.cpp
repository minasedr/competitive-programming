class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    void f(int i, int sum, vector<int> cand, int target) {
        if (sum >= target || i >= cand.size()) {
            if (sum == target)
                res.push_back(cur);
            return;
        }
        
        for (int j = i; j < cand.size(); j++) {
            cur.push_back(cand[j]);
            f(j, sum + cand[j], cand, target);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        f(0, 0, candidates, target);
        return res;
    }
};