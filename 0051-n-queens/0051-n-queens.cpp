class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> cur(n, string(n, '.'));
        unordered_set<int> diag, anti_diag, vert;

        function<bool(int, int)> inbound = [&](int r, int c) {
            return (r >= 0 and r < n and c >= 0 and c < n);
        };
        function<bool(int, int)> valid = [&](int r, int c) {
            if (not inbound(r, c))
                return false;
            if (anti_diag.count(r - c) || diag.count(r + c))
                return false;
            if (vert.count(c))
                return false;
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
            diag.insert(r + c);
            anti_diag.insert(r - c);
            vert.insert(c);
            cur[r][c] = 'Q';
            for (int j = 0; j < n; j++) {
                if (valid(r + 1, j))
                    dfs(r + 1, j);
            }
            cur[r][c] = '.';
            diag.erase(r + c);
            anti_diag.erase(r - c);
            vert.erase(c);
        };
        int cnt = 0;
        for (int j = 0; j < n; j++)
            dfs(0, j);
        return ans;
    }
};