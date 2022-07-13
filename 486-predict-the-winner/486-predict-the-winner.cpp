class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(), vector<int>(nums.size()));
        int n = nums.size();
        for (int i = n; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j)
                    dp[i][j] = nums[i];
                else {
                    int a = nums[i] - dp[i+1][j];
                    int b = nums[j] - dp[i][j-1];
                    dp[i][j] = max(a,b);
                }
            }
        }
        return dp[0][n-1] >= 0;
    }
};