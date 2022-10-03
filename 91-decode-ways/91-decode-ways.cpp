class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1);
        if (n == 1 && s[0] == '0')
            return 0;
        
        dp[n] = 1; 
        dp[n - 1] = (s[n - 1] != '0');
        
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] != '0')
                dp[i] += dp[i + 1];
            if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))
                dp[i] += dp[i + 2];
        }
        return dp[0];
    }
};