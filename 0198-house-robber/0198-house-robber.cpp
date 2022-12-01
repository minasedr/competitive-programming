class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        
        for (int i = 0; i < n; i++) {
            int take = nums[i], dont = 0;
            if (i > 1)
                take += dp[i - 2];
            if (i > 0)
                dont = dp[i - 1];
            dp[i] = max(take, dont);
        }
        return dp[n - 1];
    }
};