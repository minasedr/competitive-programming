class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        function<void(int, int)> dfs = [&](int r, int c) {
            if (r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == 0)
                return;
            grid[r][c] = 0;
            dfs(r + 1, c);
            dfs(r - 1, c);
            dfs(r, c + 1);
            dfs(r, c - 1);
        };
        function<bool(int,int)> boundary = [&](int r, int c) {
            return (r == 0 || r == n -1 || c == 0 || c == m - 1);
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (boundary(i,j) && grid[i][j] == 1)
                    dfs(i, j);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    ans++;
            }
        }
        return ans;
    }
};