class Solution {
public:
    bool divisorGame(int n) {
        vector<bool>dp(n, false);
        for (int i = 1; i <= n; i++)
            dp[i] = (dp[i-1] == false ? true: false);
            
        return dp.back();
    }
};