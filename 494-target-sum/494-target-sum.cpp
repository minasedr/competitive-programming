class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n, vector<int>(2 * total + 1));
        dp[0][nums[0] + total] = 1;
        dp[0][-nums[0] + total] += 1;
        
        for (int i = 1; i < n; i++) {
            for (int j = -total; j <= total; j++) {
                if (dp[i - 1][j + total] > 0) {
                    dp[i][j + nums[i] + total] += dp[i - 1][j + total];
                    dp[i][j - nums[i] + total] += dp[i - 1][j + total];
                }
            }
        }
        return abs(target) > total ? 0 : dp[n - 1][target + total];
    }
};