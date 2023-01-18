class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<long long> dp(target + 1);
        dp[0] = 1;
        
        for (int sum = 1; sum <= target; sum++) {
            for (int j = 0; j < n; j++) {
                if (sum >= nums[j])
                    dp[sum] += dp[sum - nums[j]] % INT_MAX;
            }
        }
        return dp[target];
    }
};