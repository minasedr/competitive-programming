class Solution {
public:
    int knightDialer(int n) {
        const int MOD = 1e9 + 7;
        
        vector<vector<int>> paths = {{4, 6}, {6, 8}, {7, 9}, 
                                    {4, 8}, {0, 3, 9}, {},
                                    {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
        vector<vector<long>> dp(n + 1, vector<long>(10));
        
        fill(dp[1].begin(), dp[1].end(), 1);
        
        for (int i = 2; i <= n; i++)
            for (int j = 0; j < 10; j++)
                for (int p : paths[j])
                    (dp[i][j] += dp[i - 1][p]) %= MOD;
        
        long sum = 0;
        for (int i = 0; i < 10; i++)
            (sum += dp[n][i]) %= MOD;
        return sum;
    }
};