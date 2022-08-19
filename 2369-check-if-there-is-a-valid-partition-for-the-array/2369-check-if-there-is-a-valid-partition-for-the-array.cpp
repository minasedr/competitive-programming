class Solution {
public:
    map<int, bool> memo;
    bool dp(int idx, vector<int>nums) {
        if (idx >= nums.size())
            return true;
        if (memo.count(idx)) 
            return memo[idx];
        
        if (idx < nums.size() - 1 && nums[idx] == nums[idx + 1])
            if (dp(idx + 2, nums)) 
                return true;
        
        if (idx < nums.size() - 2 && nums[idx] == nums[idx + 1] && nums[idx + 1] == nums[idx + 2])
            if (dp(idx + 3, nums)) 
                return true;
        if (idx < nums.size() - 2 && nums[idx] + 1 == nums[idx + 1] && nums[idx + 1] + 1 == nums[idx + 2])
            if(dp(idx + 3, nums)) 
                return true;
        memo[idx] = false;
        return false;
    }
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool>dp(n);
        for (int i = n - 1; i >= 0; i--) {
            if (i < n - 1 && nums[i] == nums[i + 1])
                dp[i] =  dp[i] || (i == n - 2 || dp[i + 2]);
            if (i < n - 2 && nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2])
                dp[i] =  dp[i] || (i == n - 3 || dp[i + 3]);
            if (i < n - 2 && nums[i] + 1 == nums[i + 1] && nums[i + 1] + 1 == nums[i + 2])
                dp[i] = dp[i] || (i == n - 3 || dp[i + 3]);
        }
        return dp[0];
        
            }
};