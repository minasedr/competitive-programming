class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(305, vector<int>(305, -1));
        
        function<int(int, int)> dfs;
        dfs = [&](int left, int right) {
            if (left > right)
                return 0;
            if (dp[left][right] != -1)
                return dp[left][right];
            int ans = 0;
            for (int k = left; k <= right; k++)
                ans = max(ans, dfs(left, k - 1) + (nums[left - 1] * nums[k] * nums[right + 1]) + dfs(k + 1, right));
            
            return dp[left][right] = ans;
        };
        
        return dfs(1, nums.size() - 2);
    }
};