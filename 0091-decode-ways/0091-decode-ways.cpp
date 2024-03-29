class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 2);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != '0')
                dp[i] += dp[i + 1];
            if (s[i] == '1' or (i < n - 1 and s[i] == '2' and s[i + 1] <= '6'))
                dp[i] += dp[i + 2];
        }
        return dp[0];
    }
};