class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        function<int(int, bool)> dfs;
        dfs = [&](int i, bool sold) {
            if (i >= n) return 0;
            if (dp[i][sold] != -1) return dp[i][sold];
            int buy = 0, sell = 0, cool = 0;
            if (sold)
                buy = dfs(i + 1, false) - prices[i];
            else
                sell = dfs(i + 2, true) + prices[i];
            cool = dfs(i + 1, sold);
            return dp[i][sold] = max({buy, sell, cool});
        };
        
        return dfs(0, true);
    }
};