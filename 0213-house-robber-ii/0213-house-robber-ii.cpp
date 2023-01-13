class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> dp(n + 1, -1);
        
        function<int(int, int)> dfs;
        dfs = [&](int i, int n) {
            if (i >= n) return 0;
            if (dp[i] != -1)
                return dp[i];
            int rob = nums[i] + dfs(i + 2, n);
            int dont = dfs(i + 1, n);
            return dp[i] = max(rob, dont);;
        };
        int ans = dfs(0, n - 1);
        fill(dp.begin(), dp.end(), -1);
        ans = max(ans, dfs(1, n));
        return ans;
    }
};