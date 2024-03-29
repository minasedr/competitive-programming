class NumMatrix {
public:
    int grid[205][205]{};
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                grid[i][j] = grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1] + matrix[i - 1][j - 1];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return grid[row2 + 1][col2 + 1] - grid[row2 + 1][col1] - grid[row1][col2 + 1] + grid[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */