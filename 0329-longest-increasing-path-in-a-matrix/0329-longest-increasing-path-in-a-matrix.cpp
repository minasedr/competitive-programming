class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(202, vector<int>(202));
        
        function<int(int, int, int)> dfs;
        dfs = [&] (int r, int c, int par) {
            if (r < 0 || r >= n || c < 0 || c >= m || matrix[r][c] <= par)
                return 0;
            if (dp[r][c]) return dp[r][c];
            dp[r][c] = 1 + max({dfs(r + 1, c, matrix[r][c]), dfs(r - 1, c, matrix[r][c]), dfs(r, c + 1, matrix[r][c]), dfs(r, c - 1, matrix[r][c])});
            return dp[r][c];
        };
        
        int ans = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, dfs(i, j, -1));
            }
        }
        return ans;
    }
};