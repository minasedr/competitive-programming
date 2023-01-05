class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n + 1, vector<int>(2 * sum + 1, -1));
        int k = sum;
        function<bool(int, int)> dfs;
        dfs = [&](int i, int cur) {
            if (i >= n)
                return (cur == 0);
            if (dp[i][cur + k] != -1)
                return dp[i][cur + k] > 0;
            if (dfs(i + 1, cur + nums[i]) or dfs(i + 1, cur - nums[i]))
                return (dp[i][cur + k] = 1) > 0;
            return (dp[i][cur + k] = 0) > 0;
        };
        
        return dfs(0, 0);
    }
};