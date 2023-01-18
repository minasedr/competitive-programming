class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target + 1, -1);
        
        function<int(int)> dfs;
        dfs = [&](int target) {
            if (target < 0) return 0;
            if (target == 0) return 1;
            if (dp[target] != -1)
                return dp[target];
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                cnt += dfs(target - nums[j]);
            }
            return dp[target] = cnt;
        };
        
        return dfs(target);
    }
};