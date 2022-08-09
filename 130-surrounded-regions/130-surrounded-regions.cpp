class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        function<void(int, int)> dfs = [&](int r, int c) {
            if (r < 0 || r >= n || c < 0 || c >= m || vis[r][c] == true || board[r][c] == 'X')
                return;
            vis[r][c] = true;
            dfs(r + 1, c);
            dfs(r - 1, c);
            dfs(r, c + 1);
            dfs(r, c - 1);
        };
        function<bool(int, int)> boundary = [&](int r, int c) {
            return (r == 0 || c == 0 || r == n - 1 || c == m - 1);
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && boundary(i, j) && board[i][j] == 'O')
                    dfs(i, j);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};