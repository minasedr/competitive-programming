class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), ans = n;
        vector<vector<int>> dp(n, vector<int>(n));
        
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;
        for (int i = 0; i < n - 1; i++)
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = 1;
                ans++;
            }
        for (int len = 3; len <= n; len++) {
            for (int beg = 0; beg < n - len + 1; beg++) {
                int end = beg + len - 1;
                if (dp[beg + 1][end - 1] == 1 && s[beg] == s[end]) {
                    dp[beg][end] = 1;
                    ans++;
                }
            }
        }
        return ans;
    }
};