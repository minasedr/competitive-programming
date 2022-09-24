class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if (sum & 1) return false;
        sum /= 2;
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        
        for (auto c: nums) {
            for (int i = sum; i >= c; i--)
                dp[i] = dp[i] || dp[i - c];
        }
        return dp[sum];
    }
};