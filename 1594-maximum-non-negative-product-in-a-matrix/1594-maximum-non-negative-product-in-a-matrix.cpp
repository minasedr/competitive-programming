class Solution {
public:
    const int MOD = 1e9 + 7;
    int maxProductPath(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        vector<vector<long long>> mx(r, vector<long long> (c)), mn(r, vector<long long> (c));
        mx[0][0] = mn[0][0] = grid[0][0];
        for (int i = 1; i < r; i++)
            mx[i][0] = mn[i][0] = mx[i - 1][0] * grid[i][0];
        
        for (int j = 1; j < c; j++)
            mx[0][j] = mn[0][j] = mx[0][j-1] * grid[0][j];
        
        for (int i = 1; i < r; i++) {
            for (int j = 1; j < c; j++) {
                if (grid[i][j] < 0) {
                    mx[i][j] = min(mn[i-1][j], mn[i][j-1]) * grid[i][j];
                    mn[i][j] = max(mx[i-1][j], mx[i][j-1]) * grid[i][j];
                } else {
                    mx[i][j] = max(mx[i-1][j], mx[i][j-1]) * grid[i][j];
                    mn[i][j] = min(mn[i-1][j], mn[i][j-1]) * grid[i][j];
                }
            }
        }
        int ans = mx[r-1][c-1] % MOD;
        return (ans < 0 ? -1: ans);
    }
};