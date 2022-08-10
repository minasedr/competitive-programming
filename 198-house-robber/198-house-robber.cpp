class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            if (i < 2)
                dp[i] = nums[i];
            else {
                int left = (i - 3 >= 0 ? dp[i-3] : 0);
                int right = (i - 2 >= 0 ? dp[i-2] : 0);
                dp[i] = max(left, right) + nums[i];
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};