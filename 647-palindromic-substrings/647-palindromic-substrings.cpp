class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), ans = n;
        vector<vector<bool>> dp(n, vector<bool>(n));
        
        for (int i = 0; i < n; i++)
            dp[i][i] = true;
        
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                ans++;
            }
        }
        
        for (int len = 3; len <= n; len++) {
            for (int beg = 0; beg + len <= n; beg++) {
                int end = beg + len - 1;
                if (dp[beg + 1][end - 1] && s[beg] == s[end]) {
                    dp[beg][end] = true;
                    ans++;
                }
            }
        }
        return ans;
    }
};