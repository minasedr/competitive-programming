class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        vector<int> dp(n + 1);
        dp[1] = nums[1];
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        int ans = *max_element(dp.begin(), dp.end());
        fill(dp.begin(), dp.end(), 0);
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);
        for (int i = 2; i < n - 1; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        ans = max(ans, *max_element(dp.begin(), dp.end()));
        return ans;
    }
};