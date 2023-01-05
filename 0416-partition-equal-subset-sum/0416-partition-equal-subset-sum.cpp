class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) return false;
        sum /= 2;
        vector<bool> dp(sum + 1);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int w = sum; w >= 0; w--) {
                if (w >= nums[i - 1])
                    dp[w] = (dp[w] | dp[w - nums[i - 1]]);
            }
        }
        return dp[sum];
    }
};