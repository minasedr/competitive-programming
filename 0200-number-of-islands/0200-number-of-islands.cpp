class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<bool>> vis(row, vector<bool>(col));
        
        function<int(int,int)> dfs = [&](int x, int y) {
            if (x < 0 || x >= row || y < 0 || y >= col || grid[x][y] == '0' || vis[x][y])
                return 0;
            vis[x][y] = true;
            dfs(x + 1, y);
            dfs(x - 1, y);
            dfs(x, y + 1);
            dfs(x, y - 1);
            return 1;
        };
        
        int ans = 0;
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (grid[r][c] == '1' && !vis[r][c]) {
                    ans += dfs(r, c);
                }
            }
        }
        return ans;
    }
};