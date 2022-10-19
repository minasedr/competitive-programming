class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int dir[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        vector<vector<int>> ans;
        int row = rStart, col = cStart;
        for (int step = 1, d = 0; ans.size() < rows * cols; step++) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < step; j++) {
                    if (row >= 0 and row < rows and col >= 0 and col < cols)
                        ans.push_back({row, col});
                    row += dir[d][0];
                    col += dir[d][1];
                }
                d = (d + 1) % 4;
            }
        }
        return ans;
    }
};