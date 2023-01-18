class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int K) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(K + 1, -1)));
        vector<vector<bool>> vis(m + 1, vector<bool>(n + 1));
        
        function<int(int, int, int)> dfs;
        dfs = [&](int r, int c, int k) {
            if (r == 0 and c == 0)
                return 0;
            if (r < 0 or r >= m or c < 0 or c >= n or vis[r][c])
                return (int)1e6;
            if (dp[r][c][k] != -1)
                return dp[r][c][k];
            
            if (grid[r][c] == 1) {
                if (k == 0) return (int)1e6;
                k--;
            }
            vis[r][c] = true;
            dp[r][c][k] = 1 + min({dfs(r - 1, c, k), dfs(r, c - 1, k), dfs(r + 1, c, k), dfs(r, c + 1, k)});
            vis[r][c] = false;
            return dp[r][c][k];
        };
        
        int ans = dfs(m - 1, n - 1, K);
        return (ans > m * n ? -1 : ans);
    }
};