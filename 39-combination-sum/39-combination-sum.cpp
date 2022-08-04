class Solution {
public:
    vector<vector<int>> res;
    
    vector<vector<int>> bt(int i, int cur, vector<int> & tmp, int N, vector<int>& cand, int target) {
     if (i >= N || cur > target)
            return {};
        if (cur == target) {
            res.push_back(tmp);
            return {};
        }
        for (int j = i; j < N; j++) {
            tmp.push_back(cand[j]);
            bt(j, cur + cand[j], tmp, N, cand, target);
            tmp.pop_back();
        }
        return res;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();        
        vector<int> tmp;
        return bt(0, 0, tmp, n, candidates, target);        
    }
};