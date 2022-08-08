class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0, n = grid.size(), m = grid[0].size();

        function<int(int, int)> dfs = [&](int r, int c) {
            if (r < 0 || r >= n || c < 0 || c >= m)
                return 0;
            if (grid[r][c] == 0)
                return 0;
            grid[r][c] = 0;
            ans++;
            dfs(r + 1, c);
            dfs(r - 1, c);
            dfs(r, c + 1);
            dfs(r, c - 1);
            return ans;
        };
        
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    ans = 0;
                    maxArea = max(maxArea, dfs(i, j));
                }
            }
        }
        return maxArea;
    }
};