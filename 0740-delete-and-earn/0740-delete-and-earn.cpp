class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> dp(10005, -1);
        map<int, int> cnt;
        
        for (auto n: nums)
            cnt[n] += n;
        
        function<int(int)> dfs;
        dfs = [&](int n) {
            if (n > 10001) return 0;
            if (dp[n] != -1)
                return dp[n];
            return dp[n] = max(dfs(n + 1), cnt[n] + dfs(n + 2));
        };
        
        return dfs(1);
    }
};