class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        vector<int> dp(n + 1);
        
        for (auto n: nums)
            dp[n] += n;
        
        for (int i = 2; i <= n; i++)
            dp[i] = max(dp[i - 1], dp[i - 2] + dp[i]);
        
        return dp[n];
    }
};