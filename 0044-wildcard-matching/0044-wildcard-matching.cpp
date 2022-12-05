class Solution {
public:
    bool isMatch(string s, string p) {
        map<pair<int, int>, bool> dp;
        function<bool(int, int)> dfs;
        dfs = [&](int i, int j) {
            if (j < 0) return i < 0;
            if (i < 0) {
                for (int k = 0; k <= j; k++)
                    if (p[k] != '*')
                        return false;
                return true;
            }
            if (dp.count({i, j}))
                return dp[{i, j}];
            if (s[i] == p[j] || p[j] == '?') {
                 if (dfs(i - 1, j - 1))
                    return dp[{i, j}] = true;
            }
            else if (p[j] == '*') {
                if (dfs(i - 1, j - 1) || dfs(i, j - 1) || dfs(i - 1, j))
                    return dp[{i, j}] = true;
            }
            return dp[{i, j}] = false;
        };
        return dfs(s.size() - 1, p.size() - 1);
    }
};