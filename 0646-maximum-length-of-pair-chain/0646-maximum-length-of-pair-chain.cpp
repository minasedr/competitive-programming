class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size(), k = 1001;
        sort(pairs.begin(), pairs.end(), [&](auto a, auto b) {
            if (a[1] == b[1])
                return a[0] < b[0];
            return a[1] < b[1];
        });
        vector<vector<int>> dp(n + 1, vector<int>(3001, -1));
        
        function<int(int, int)> dfs;
        dfs = [&](int i, int prev) {
            if (i >= n) return 0;
            if (dp[i][prev + k] != -1)
                return dp[i][prev + k];
            int cnt = 0;
            if (prev < pairs[i][0])
                cnt = 1 + dfs(i + 1, pairs[i][1]);
            return dp[i][prev + k] = max(cnt, dfs(i + 1, prev));
        };
        
        return dfs(0, -1000);
    }
};