class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        function<int(int, int)> dfs;
        dfs = [&](int i, int sum) {
            if (i >= n or sum < 0) return (int)1e5;
            if (sum == 0) return 0;
            if (dp[i][sum] != -1) return dp[i][sum];
            return dp[i][sum] = min(1 + dfs(i, sum - coins[i]), dfs(i + 1, sum));
        };
        int ans = dfs(0, amount);
        return (ans >= 1e5 ? -1 : ans);
    }
};