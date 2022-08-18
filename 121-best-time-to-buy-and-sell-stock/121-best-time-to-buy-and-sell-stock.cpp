class Solution {
public:
    int ans = 0;
    map<int, int> memo;
    int dp(int idx, int prev, vector<int>& prices) {
        int n = prices.size();
        if (idx >= n) return 0;
        if (memo[idx])
            return memo[idx];
        ans = max(ans, prices[idx] - prev);
        dp(idx + 1, min(prev, prices[idx]), prices);
        return ans;
    }
    int maxProfit(vector<int>& prices) {
        return dp(0, prices[0], prices);
    }
};