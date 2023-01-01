class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, -1);
        function<int(int)> dfs;
        dfs = [&](int i) {
            if (i <= 1) return 1;
            if (dp[i] != -1) return dp[i];
            int cnt = 0;
            for (int j = 1; j <= i; j++)
                cnt += dfs(j - 1) * dfs(i - j);
            return dp[i] = cnt;
        };
        return dfs(n);
    }
};