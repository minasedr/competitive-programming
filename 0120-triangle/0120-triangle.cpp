class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(), m = triangle[n - 1].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e6));
        dp[0][0] = triangle[0][0];
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                if (j == 0)
                    dp[i][j] = dp[i - 1][j];
                int topL = 1e6;
                if (j > 0)
                    topL = dp[i - 1][j - 1];
                int top = 1e6;
                if (j < triangle[i].size() - 1)
                    top = dp[i - 1][j];
                dp[i][j] = triangle[i][j] + min(top, topL);
            }
        }
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};