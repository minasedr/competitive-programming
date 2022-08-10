class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n + 1, 1e9), res;
        dp[0] = 0;
        for (int i = 1; i * i <= n; i++) {
            res.push_back(i*i);
        }
        for (int i = 1; i <= n; i++) {
            for (auto c: res) {
                if (i - c >= 0)
                    dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
        return dp[n];
    }
};