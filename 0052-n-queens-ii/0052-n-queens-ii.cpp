class Solution {
public:
    int totalNQueens(int n) {
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
        
        function<int(int, int)> dfs;
        dfs = [&](int r, int c) {
            if (r >= n - 1)
                return 1;
            int ans = 0;
            diag.insert(r + c);
            anti_diag.insert(r - c);
            vert.insert(c);
            for (int j = 0; j < n; j++) {
                if (valid(r + 1, j))
                    ans += dfs(r + 1, j);
            }
            diag.erase(r + c);
            anti_diag.erase(r - c);
            vert.erase(c);
            return ans;
        };
        int cnt = 0;
        for (int j = 0; j < n; j++)
            cnt += dfs(0, j);
        return cnt;    
    }
};