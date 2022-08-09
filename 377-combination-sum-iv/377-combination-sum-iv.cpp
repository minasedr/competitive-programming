class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long> dp(target + 1, 0);
        dp[0] = 1;
        
        for (int x = 1; x <= target; x++) {
            for (auto c: nums) {
                if (x - c >= 0)
                    dp[x] += dp[x - c] % INT_MAX;
            }
        }
        return dp[target];
    }
};