class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int dp[200];
        for (int i = 0; i < m; i++) {
            if (i > 0)
                dp[i] = dp[i-1] + grid[0][i];
            else
                dp[i] = grid[0][i];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0 ;j < m; j++) {
                int left = j > 0 ? dp[j-1]: 1e9;
                dp[j] = grid[i][j] + min(dp[j], left);
            }
        }
        return dp[m-1];
    }
};