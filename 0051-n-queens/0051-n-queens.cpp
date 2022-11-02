class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> cur(n, string(n, '.'));
        set<array<int,2>> vis;

        function<bool(int, int)> inbound = [&](int r, int c) {
            return (r >= 0 and r < n and c >= 0 and c < n);
        };
        function<bool(int, int)> valid = [&](int r, int c) {
            if (not inbound(r, c))
                return false;
            for (auto [nr, nc] : vis) {
                if (nr + nc == r + c)
                    return false;
                if (nr - nc == r - c)
                    return false;
                if (nr == r || nc == c)
                    return false;
            }
            return true;
        };
        
        function<void(int, int)> dfs;
        dfs = [&](int r, int c) {
            if (r >= n - 1) {
                cur[r][c] = 'Q';
                ans.push_back(cur);
                cur[r][c] = '.';
                return;
            }
            
            vis.insert({r, c});
            cur[r][c] = 'Q';
            for (int j = 0; j < n; j++) {
                if (valid(r + 1, j))
                    dfs(r + 1, j);
            }
            cur[r][c] = '.';
            vis.erase({r, c});
        };
        int cnt = 0;
        for (int j = 0; j < n; j++)
            dfs(0, j);
        return ans;
    }
};