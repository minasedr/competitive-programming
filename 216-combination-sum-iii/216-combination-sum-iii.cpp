class Solution {
public:
    vector<vector<int>> res;
    vector<int>ans;
    void dp(int i, int cur, int k, int n) {
        if (cur >= n || ans.size() >= k) {
            if (cur == n && ans.size() == k)
                res.push_back(ans);
            return;
        }
        for (int j = i + 1; j <= 9; j++){
            ans.push_back(j);
            dp(j, cur + j, k, n);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        dp(0, 0, k, n);
        return res;
    }
};