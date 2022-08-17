class Solution {
public:
    int memo[2005][2005];
    int dp(int idx, int cur, vector<int>& nums, int target) {
        if (idx >= nums.size())
            return (cur == target);
        if (memo[idx][cur + 1000] == 0) {
            int add = dp(idx + 1, cur + nums[idx], nums, target);
            int sub = dp(idx + 1, cur - nums[idx], nums, target);
            memo[idx][cur + 1000] = add + sub;
        }
        return memo[idx][cur + 1000];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return dp(0, 0, nums, target);
    }
};