class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0)
                    grid[i][j] = grid[i][j];
                else if (i && j == 0)
                    grid[i][j] = grid[i][j] + grid[i-1][j];
                else if (j && i == 0)
                    grid[i][j] = grid[i][j] + grid[i][j-1];
                else 
                    grid[i][j] = min(grid[i-1][j], grid[i][j-1]) + grid[i][j];
            }
        }
        return grid[n - 1][m - 1];
    }
};


