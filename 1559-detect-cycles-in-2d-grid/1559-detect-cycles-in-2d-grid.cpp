class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m));
        int dir[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        function<bool(int, int)> inbound = [&](int r, int c) {
            return (r >= 0 and r < n and c >= 0 and c < m);
        };
        function<bool(int,int,int,int,char)> dfs;
        
        dfs = [&](int r, int c, int pr, int pc, char color) {
            vis[r][c] = true;
            for (auto d: dir) {
                int nr = r + d[0];
                int nc = c + d[1];
                if (nr == pr and nc == pc)
                    continue;
                if (inbound(nr, nc) && grid[nr][nc] == color) {
                    if (vis[nr][nc] || dfs(nr, nc, r, c, color))
                        return true;
                }
            }
            return false;
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] and dfs(i, j, -1, -1, grid[i][j]))
                    return true;
            }
        }
        return false;
    }
};