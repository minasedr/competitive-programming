class Solution {
public:
    int numSquares(int n) {
        vector<int> coins, dp(n + 1, 1e9);
        for (int i = 1; i * i <= n; i++)
            coins.push_back(i * i);
        
        dp[0] = 0;
        for (int s = 0; s <= n; s++) {
            for (auto c: coins) {
                if (s >= c)
                    dp[s] = min(dp[s], dp[s - c] + 1);
            }
        }
        return dp[n];
    }
};
