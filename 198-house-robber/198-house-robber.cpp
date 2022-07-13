class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int dp[101];
        for (int i = 0; i < n; i++) {
            int fir = i > 0 ? dp[i-1]: 0;
            int sec = i > 1? dp[i-2]: 0;
            dp[i] = max(fir, sec + nums[i]);
        }
        return dp[n-1];
    }
};