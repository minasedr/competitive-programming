class Solution {
public:
    unordered_map<int, int> memo;
    int dp(int idx, vector<int>& cost) {
        if (idx <= 1)
            return cost[idx];
        if (memo[idx]) return memo[idx];
        memo[idx] = cost[idx] + min(dp(idx - 1, cost), dp(idx - 2, cost));
        return memo[idx];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return min(dp(n - 1, cost), dp(n - 2, cost));
    }
};