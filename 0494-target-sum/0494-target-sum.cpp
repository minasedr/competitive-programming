class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(3000, -1));
        
        function<int(int, int)> dfs;
        dfs = [&](int i, int cur) {
            if (i >= n) 
                return (int)(cur == target);
            if (dp[i][cur + 1000] != -1)
                return dp[i][cur + 1000];
            return dp[i][cur + 1000] = dfs(i + 1, cur + nums[i]) + dfs(i + 1, cur - nums[i]);
        };
        
        return dfs(0, 0);
    }
};