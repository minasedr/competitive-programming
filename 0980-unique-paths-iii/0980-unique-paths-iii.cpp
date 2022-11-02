class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int dir[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int n = grid.size(), m = grid[0].size();
        int cells = 0;
        
        vector<vector<bool>> vis(n, vector<bool>(m));
        function<bool(int, int)> inbound = [&](int r, int c) {
            return (r >= 0 and r < n and c >= 0 and c < m);
        };
        function<int(int, int, int)> dfs;
        dfs = [&](int r, int c, int cnt) {
            if (vis[r][c] || grid[r][c] == -1)
                return 0;
            if (grid[r][c] == 2)
                return (cnt == cells ? 1: 0);
            int ans = 0;
            vis[r][c] = true;
            for (auto d: dir) {
                int nr = r + d[0];
                int nc = c + d[1];
                if (inbound(nr, nc))
                    ans += dfs(nr, nc, cnt + (grid[nr][nc] == 0));
            }
            vis[r][c] = false;
            return ans;
        };
        int row = 0, col = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    row = i, col = j;
                cells += (grid[i][j] == 0);

            }
        
        return dfs(row, col, 0);
    }
};