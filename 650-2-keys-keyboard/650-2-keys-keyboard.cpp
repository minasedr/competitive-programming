class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1, 1e9);
        dp[0] = dp[1] = 0;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 2; i * j <= n; j++) {
                int k = i * j;
                dp[k] = min(dp[k], dp[i] + j);
            }
        }
        return dp[n];
    }
};