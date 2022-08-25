class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), start = 0, maxLen = 1;
        vector<vector<int>> dp(n, vector<int>(n));
        
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = 1;
                start = i;
                maxLen = 2;
            }
        }
        for (int len = 3; len <= n; len++) {
            for (int beg = 0; beg < n - len + 1; beg++) {
                int end = beg + len - 1;
                if (dp[beg + 1][end - 1] == 1 && s[beg] == s[end]) {
                    dp[beg][end] = 1;
                    start = beg;
                    maxLen = len;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};