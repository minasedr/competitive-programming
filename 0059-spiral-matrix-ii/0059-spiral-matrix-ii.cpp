class Solution {
public:
    vector<vector<int>> newMatrix;
    int value = 1;
    bool inBound(int row, int col, int n) {
        if (row < 0 || row >= n)
            return false;
        if (col < 0 || col >= n)
            return false;
        return true;
    }
    void spiralMove(int row, int col, int n) {
        if (not inBound(row, col, n))
            return;
        if (newMatrix[row][col] != 0)
            return;
        newMatrix[row][col] = value;
        value += 1;
        if (col + 1 >= row)
            spiralMove(row, col + 1, n);
        spiralMove(row + 1, col, n);
        spiralMove(row, col - 1, n);
        spiralMove(row - 1, col, n);
    }
    
    vector<vector<int>> generateMatrix(int n) {
        newMatrix.resize(n, vector<int>(n));
        spiralMove(0, 0, n);
        
        return newMatrix;
    }
};