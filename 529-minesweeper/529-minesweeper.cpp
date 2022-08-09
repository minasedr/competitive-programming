class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m, false));
        int dir[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, 
                        {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        
        function<bool(int,int)> bounded = [&](int r, int c) {
            return (r >= 0 && r < n && c >= 0 && c < m);
        };
        
        function<void(int, int)> dfs = [&] (int r, int c) {
            if (r < 0 || r >= n || c < 0 || c >= m || board[r][c] == 'B' || isdigit(board[r][c]))
                return;
            vis[r][c] = true;
            if (board[r][c] == 'M')
                board[r][c] = 'X';
            else {
             
                int cnt = 0;
                for (auto d : dir) {
                    int dr = d[0] + r;
                    int dc = d[1] + c;
                    if (bounded(dr,dc) && board[dr][dc] == 'M')
                        cnt++;
                }
                if (cnt)
                    board[r][c] = char('0' + cnt);
                else {
                    board[r][c] = 'B';
                    for (auto d: dir) {
                        int dr = r + d[0];
                        int dc = c + d[1];
                        if (bounded(dr, dc) && !vis[dr][dc] && (board[dr][dc] == 'M' || board[dr][dc] == 'E'))
                            dfs(dr, dc);
                    }
                }
            }
        };
        dfs(click[0], click[1]);
        return board;
    }
};