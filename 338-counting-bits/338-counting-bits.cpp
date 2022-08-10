class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>dp(n + 1);
        for (int i = 0; i <= n; i++) {
            if (i < 2)
                dp[i] = i;
            else
                dp[i] = dp[i/2] + (i & 1 ? 1 : 0);
        }
        return dp;
    }
};