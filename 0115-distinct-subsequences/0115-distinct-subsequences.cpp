using i64 = long long;
class Solution {
public:
    int numDistinct(string s, string t) {
        
        int n = s.size(), m = t.size();
        vector<vector<i64>> dp(m + 1, vector<i64>(n + 1));
        fill(dp[0].begin(), dp[0].end(), 1);
        const int MOD = INT_MAX;
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (t[i - 1] == s[j - 1])
                    dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1]) % MOD;
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
};