class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> dp(10005);
        
        for (auto n: nums)
            dp[n] += n;
        
        for (int n = 2; n <= 10000; n++)
            dp[n] = max(dp[n - 1], dp[n - 2] + dp[n]);
        
        return dp[10000];
    }
};