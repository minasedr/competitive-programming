class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n + 1, vector<int>(3000, -1)));
        
        function<int(int, int, bool)> dfs;
        dfs = [&](int i, int prev, bool diff) {
            if (i >= n) return 0;
            if (dp[diff][i][prev + 1] != -1)
                return dp[diff][i][prev + 1];
            int cnt = 0;
            if (nums[i] - prev > 0 and not diff)
                cnt = 1 + dfs(i + 1, nums[i], !diff);
            else if (nums[i] - prev < 0 and diff)
                cnt = 1 + dfs(i + 1, nums[i], !diff);
            cnt = max(cnt, dfs(i + 1, prev, diff));
            return dp[diff][i][prev + 1] = cnt;
        };
        
        return max(dfs(0, 1001, true), dfs(0, -1, false));
    }
};