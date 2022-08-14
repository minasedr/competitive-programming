class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n, vector<int>(n));
        dp[0][0] = triangle[0][0];
        
        for (int i = 1; i < n; i++) {
            int m = triangle[i-1].size();
            for (int j = 0; j < triangle[i].size(); j++) {
                int tp = (j > 0 ? dp[i-1][j-1]: INT_MAX);
                int tr = (j < m ? dp[i-1][j] : INT_MAX);
                dp[i][j] = min(tp, tr) + triangle[i][j];
            }
        }
        return *min_element(dp.back().begin(), dp.back().end());
    }
};