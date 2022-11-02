class Solution {
public:
    int totalNQueens(int n) {
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
        
        function<int(int, int)> dfs;
        dfs = [&](int r, int c) {
            if (r >= n - 1) return 1;
            int ans = 0;
            
            vis.insert({r, c});
            for (int j = 0; j < n; j++) {
                if (valid(r + 1, j))
                    ans += dfs(r + 1, j);
            }
            vis.erase({r, c});
            return ans;
        };
        int cnt = 0;
        for (int j = 0; j < n; j++)
            cnt += dfs(0, j);
        return cnt;
    }
};