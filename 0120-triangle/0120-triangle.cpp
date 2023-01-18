class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(), m = triangle[n - 1].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        
        function<int(int, int)> dfs;
        dfs = [&](int r, int c) {
            if (r >= n) return 0;
            if (c >= triangle[r].size())
                return (int)1e6;
            if (dp[r][c] != -1)
                return dp[r][c];
            return dp[r][c] = triangle[r][c] + min(dfs(r + 1, c), dfs(r + 1, c + 1));
        };
        
        return dfs(0, 0);
    }
};