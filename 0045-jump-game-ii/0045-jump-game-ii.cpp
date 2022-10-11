class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), cur = 0, jumps = 0;
        vector<int> dp(n);
        int farthest = 0;
        
        for (int i = 0; i < n; i++) {
            dp[i] = jumps;
            farthest = max(farthest, i + nums[i]);
            if (i == cur) {
                cur = farthest;
                jumps++;
            }
        }
        return dp[n - 1];
    }
};