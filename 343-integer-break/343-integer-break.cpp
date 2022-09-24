class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        if(n == 2)
            return 1;
        if(n == 3)
            return 2;
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        
        for (int i = 4; i <= n; i++) {
            int mx = 0;
            for (int j = 0; j <= i; j++)
                mx = max(mx, dp[j] * dp[i - j]);
            dp[i] = mx;
        }
        return dp[n]; 
    }
};