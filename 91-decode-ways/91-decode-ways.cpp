class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 1 && s[0] == '0')
            return 0;
        vector<int>dp(n);
        if (s[n - 1] != '0')
            dp[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] != '0')
                dp[i] += dp[i + 1];
            if (i + 1 < n && s[i] == '1' || s[i] == '2' && s[i + 1] <= '6')
                dp[i] += (i + 2 < n ? dp[i + 2] : 1);
        }
        return dp[0];
    }
};