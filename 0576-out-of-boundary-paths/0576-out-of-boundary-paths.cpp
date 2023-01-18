class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        const int MOD = 1e9 + 7;
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(maxMove + 1, -1)));
        
        function<int(int, int, int)> dfs;
        dfs = [&](int r, int c, int moves) {
            if (moves > maxMove) return 0;
            if (r < 0 or r >= m or c < 0 or c >= n)
                return 1;
            if (dp[r][c][moves] != -1)
                return dp[r][c][moves];
            (dp[r][c][moves] = dfs(r + 1, c, moves + 1)) %= MOD;
            (dp[r][c][moves] += dfs(r - 1, c, moves + 1)) %= MOD;
            (dp[r][c][moves] += dfs(r, c + 1, moves + 1)) %= MOD;
            (dp[r][c][moves] += dfs(r, c - 1, moves + 1)) %= MOD;
            
            return dp[r][c][moves];
        };
        
        return dfs(startRow, startColumn, 0);
    }
};