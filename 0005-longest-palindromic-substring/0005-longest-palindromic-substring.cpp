class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), start = 0, length = 1;
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = 0; i < n; i++)
            dp[i][i] = true;
        
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if ((dp[i + 1][j - 1] || len == 2) && s[i] == s[j]) {
                    dp[i][j] = true;
                    if (length < len) {
                        start = i;
                        length = len;
                    }
                }
            }
        }
        return s.substr(start, length);
    }
};