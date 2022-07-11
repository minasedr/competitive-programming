class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+2);
        for (int i = 2; i < n+2; i++) {
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i-2];
        }
        return min(dp[n], dp[n+1]);
    }
};