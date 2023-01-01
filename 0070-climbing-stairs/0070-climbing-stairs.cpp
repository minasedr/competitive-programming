class Solution {
public:
    int climbStairs(int n) {
        function<int(int)> dfs;
        vector<int> dp(45, -1);
        dfs = [&](int i) {
            if (i >= n)
                return (i == n ? 1 : 0);
            if (dp[i] != -1) return dp[i];
            return dp[i] = dfs(i + 1) + dfs(i + 2);
        };
        return dfs(0);
    }
};