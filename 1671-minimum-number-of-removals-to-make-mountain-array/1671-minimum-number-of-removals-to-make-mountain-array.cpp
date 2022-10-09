class Solution {
public:
    vector<int> LIS(vector<int> & nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return dp;
    }
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp1 = LIS(nums);
        reverse(nums.begin(), nums.end());
        vector<int> dp2 = LIS(nums);
        reverse(dp2.begin(), dp2.end());
        
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (dp1[i] > 1 && dp2[i] > 1)
            cnt = max(cnt, dp1[i] + dp2[i] - 1);
        return n - cnt;

    }
};