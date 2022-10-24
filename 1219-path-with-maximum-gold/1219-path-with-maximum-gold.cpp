class Solution {
public:    
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int dir[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int ans = 0;
        
        function<bool(int, int)> inbound = [&] (int r, int c) {
            return (r >= 0 and r < n and c >= 0 and c < m);
        };
        
        function<int(int, int)> dfs;
        dfs = [&](int r, int c) {
            if (not inbound(r, c) || grid[r][c] <= 0)
                return 0;
            int maxGold = 0;
            grid[r][c] = -grid[r][c];
            
            for (auto d: dir)
                maxGold = max(maxGold, dfs(r + d[0], c + d[1]));
            
            grid[r][c] = -grid[r][c];
            return maxGold + grid[r][c];
        };
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j])
                    ans = max(ans, dfs(i, j));
            }
        }
        return ans;
    }
};