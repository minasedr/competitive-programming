class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n);
        for (int i = 0; i < n; i++) {
            int left = (i - 2 >= 0? dp[i-2] : 0);
            int right = (i - 1 >= 0? dp[i-1] : 0);
            dp[i] = min(left, right) + cost[i];
        }
        return min(dp[n - 2], dp[n-1]);
    }
};