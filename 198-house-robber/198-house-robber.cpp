class Solution {
public:
    unordered_map<int, int> memo;
    int dp(int idx, vector<int>& nums) {
        if (idx >= nums.size()) return 0;
        if (memo[idx]) return memo[idx];
        int a = nums[idx] + dp(idx + 2, nums);
        int b = dp(idx + 1, nums);
        memo[idx] = max(a,b);
        return memo[idx];
    }
    int rob(vector<int>& nums) {
        if (!accumulate(nums.begin(), nums.end(), 0)) return 0;
        return dp(0, nums);
    }
};