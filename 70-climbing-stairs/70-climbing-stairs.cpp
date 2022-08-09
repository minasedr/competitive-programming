class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp (n + 1, 0);
        dp[0] = 1;
        for (int x = 1; x <= n; x++) {
            for (auto c: {1, 2})
                if (x - c >= 0)
                dp[x] += dp[x-c];
        }
        return dp[n];
    }
};