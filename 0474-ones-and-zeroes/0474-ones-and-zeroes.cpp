class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<vector<vector<int>>> dp(len + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        
        function<int(int, int, int)> dfs;
        dfs = [&](int i, int x, int y) {
            if (i >= len) return 0;
            if (dp[i][x][y] != -1)
                return dp[i][x][y];
            int one = count(strs[i].begin(), strs[i].end(), '1');
            int zero  = strs[i].size() - one;
            int pick = 0, dont = 0;
            if (x + zero <= m and y + one <= n)
                pick = 1 + dfs(i + 1, x + zero, y + one);
            dont = dfs(i + 1, x, y);
            return dp[i][x][y] = max(pick, dont);
        };
        
        return dfs(0, 0, 0);
    }
};