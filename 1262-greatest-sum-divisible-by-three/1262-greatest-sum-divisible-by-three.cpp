class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        
        vector<vector<int>> dp(n + 1,vector<int>(3));
        dp[0][nums[0] % 3] = nums[0];
  
        for (int i = 1; i < n; i++) {
            int cur = nums[i];
            
            if (cur % 3 == 0) {
                dp[i][0] = dp[i - 1][0] + cur;
                dp[i][1] = dp[i - 1][1] > 0 ? dp[i - 1][1] + cur : 0;
                dp[i][2] = dp[i - 1][2] > 0 ? dp[i - 1][2] + cur : 0;
            }
            
            else if (cur % 3 == 1) {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] > 0 ? dp[i - 1][2] + cur : 0);
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + cur);
                dp[i][2] = dp[i - 1][1] > 0 ? dp[i - 1][1] + cur : 0;
            }
            
            else if (cur % 3 == 2) {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] > 0 ? dp[i - 1][1] + cur : 0);
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][2] > 0 ? dp[i - 1][2] + cur : 0);
                dp[i][2] = max(dp[i - 1][2], dp[i - 1][0] + cur);
            }
        }
        return dp[n - 1][0];
    }
};