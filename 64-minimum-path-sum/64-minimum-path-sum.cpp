class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>dp(n, vector<int>(m));
        for (int i = 0; i < m; i++) {
            if (i > 0)
                dp[0][i] = dp[0][i-1] + grid[0][i];
            else
                dp[0][i] = grid[0][i];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0 ;j < m; j++) {
                int left = j > 0 ? dp[i][j-1]: 1e9;
                dp[i][j] = grid[i][j] + min(dp[i-1][j], left);
            }
        }
        return dp[n-1][m-1];
    }
};