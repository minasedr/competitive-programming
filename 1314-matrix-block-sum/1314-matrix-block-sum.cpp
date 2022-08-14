class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m)), dp(n + 1, vector<int>(m + 1));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + mat[i-1][j-1];
            }
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int a = min(i + k, n), b = min(j + k, m);
                int c = max(i - k - 1, 0), d = max(j - k - 1, 0);
                ans[i-1][j-1] = dp[a][b] - dp[c][b] - dp[a][d] + dp[c][d];
            }
        }
        return ans;
    }
};