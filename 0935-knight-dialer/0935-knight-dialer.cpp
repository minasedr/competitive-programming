class Solution {
public:
    int knightDialer(int n) {
        const int MOD = 1e9 + 7;
        int dir[][2] = {{2, 1}, {2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(20, vector<int>(20, -1)));
        
        function<int(int, int, int)> dfs;
        dfs = [&](int k, int r, int c) {
            if (r < 1 or r > 4 or c < 1 or c > 3)
                return 0;
            if (r == 4 and (c == 1 or c == 3))
                return 0;
            if (k == n) return 1;
            if (dp[k][r][c] != -1)
                return dp[k][r][c];
            int cnt = 0;
            for (auto d: dir) {
                int nr = r + d[0];
                int nc = c + d[1];
                (cnt += dfs(k + 1, nr, nc)) %= MOD;
            }
            return dp[k][r][c] = cnt;
        };
        
        int ans = 0;
        for (int r = 1; r <= 4; r++) {
            for (int c = 1; c <= 3; c++) {
                (ans += dfs(1, r, c)) %= MOD;
            }
        }
        return ans;
    }
};
//