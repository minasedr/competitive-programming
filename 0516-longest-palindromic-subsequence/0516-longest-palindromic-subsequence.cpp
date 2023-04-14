class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;
        
        for (int len = 2; len <= n; len++) {
            for (int beg = 0; beg <= n - len; beg++) {
                int end = beg + len - 1;
                if (s[beg] == s[end])
                    dp[beg][end] = dp[beg + 1][end - 1] + 2;
                else
                    dp[beg][end] = max({dp[beg][end - 1], dp[beg + 1][end], dp[beg + 1][end - 1]});
            }
        }
        
        return dp[0][n -1];
    }
};