class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int num = 1;
        vector<vector<int>> ans(n, vector<int>(n));
        function<void(int, int)> dfs;
        dfs = [&](int r, int c) {
            if (r < 0 || r >= n || c < 0 || c >= n || ans[r][c] != 0)
                return;
            ans[r][c] = num++;
            if (c + 1 >= r)
                dfs(r, c + 1);
            dfs(r + 1, c);
            dfs(r, c - 1);
            dfs(r - 1, c);
        };
        dfs(0, 0);
        return ans;
    }
};