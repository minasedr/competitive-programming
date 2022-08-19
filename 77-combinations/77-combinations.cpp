class Solution {
public:
    vector<vector<int>> res;
    void dp(int idx, int n, int k, vector<int> cur) {
        if (cur.size() == k) {
            res.push_back(cur);
            return;
        }
        
        for (int i = idx; i <= n; i++) {
            if (cur.size() < k) {
                cur.push_back(i);
                dp(i+1, n, k, cur);
                cur.pop_back();
            } else break;
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;
        dp(1, n, k, cur);
        return res;
    }
};