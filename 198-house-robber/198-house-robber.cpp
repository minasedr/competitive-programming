class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n);
        for (int i = 0; i < n; i++) {
            int left = (i-2 >= 0) ? dp[i-2]: 0;
            int right = (i-1 >= 0) ? dp[i-1]: 0;
            dp[i] = max(left + nums[i], right);
        }
        return dp[n-1];
    }
};