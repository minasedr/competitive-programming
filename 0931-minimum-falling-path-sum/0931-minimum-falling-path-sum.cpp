class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), ans = INT_MAX;
        if (n == 1)
            return matrix[0][0];
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0)
                    matrix[i][j] += min(matrix[i - 1][j], matrix[i - 1][j + 1]);
                else if (j == n - 1)
                    matrix[i][j] += min(matrix[i - 1][j - 1], matrix[i - 1][j]);
                else
                    matrix[i][j] += min({matrix[i - 1][j - 1], matrix[i - 1][j], matrix[i - 1][j + 1]});
                if (i == n - 1)
                    ans = min(ans, matrix[i][j]);
            }
        }
        return ans;
    }
};