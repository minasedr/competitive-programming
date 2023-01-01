class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp[n + 1];
        memset(dp, -1, sizeof dp);
        
        function<int(int)> dfs;
        dfs = [&](int i) {
            if (i >= n)
                return 0;
            if (dp[i] != -1) return dp[i];
            return dp[i] = cost[i] + min(dfs(i + 1), dfs(i + 2));
        };
        return min(dfs(0), dfs(1));
    }
};