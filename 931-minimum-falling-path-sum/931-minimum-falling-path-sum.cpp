class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        for (int i = 0; i < m; i++)
            dp[0][i] = matrix[0][i];
        
        for (int i = 1; i < n; i++)  {
            for (int j = 0; j < m; j++) {
                int tl = (j > 0? dp[i-1][j-1]: INT_MAX);
                int tr = (j < m - 1 ? dp[i-1][j+1]: INT_MAX);
                dp[i][j] = min({tl, dp[i-1][j], tr}) + matrix[i][j];
            }
        }
        return *min_element(dp.back().begin(), dp.back().end());
    }
};