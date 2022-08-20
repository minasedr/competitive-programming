class Solution {
public:
    vector<int> memo;
    int dp(int idx, int prev, vector<int>& nums){
        if (idx >= nums.size())
            return 0;
        if (memo[prev + 1] != -1)
            return memo[idx];
        int take = 0, dont = 0;
        if (prev == -1 || nums[prev] < nums[idx])
            take = 1 + dp(idx + 1, idx, nums);
        dont = dp(idx + 1, prev, nums);
        memo[prev + 1] = max(take, dont);
        return memo[prev + 1];
    }
    int lengthOfLIS(vector<int>& nums) {
        memo.resize(nums.size() + 1, -1);
        return dp(0, -1, nums);
    }
};
  