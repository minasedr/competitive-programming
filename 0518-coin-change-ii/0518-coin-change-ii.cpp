class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        
        function<int(int, int)> dfs;
        dfs = [&](int i, int tot) {
            if (tot == 0) return 1;
            if (i >= n or tot < 0)
                return 0;
            if (dp[i][tot] != -1)
                return dp[i][tot];
            
            return dp[i][tot] = dfs(i, tot - coins[i]) + dfs(i + 1, tot);
        };
        
        return dfs(0, amount);
    }
};