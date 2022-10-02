const int MOD = 1e9 + 7;

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1));
        
        fill(dp[1].begin(), dp[1].begin() + min(k, target) + 1, 1);
        for (int j = 2; j <= n; j++)
            for (int i = 1; i <= target; i++)
                for (int c = 1; c <= k; c++)
                    if (i > c)
                        (dp[j][i] += dp[j - 1][i - c]) %= MOD;
        
        return dp[n][target];
    }
};