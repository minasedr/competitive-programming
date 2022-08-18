class Solution {
public:
    map<pair<int, bool>, int> memo;
    int dp(int idx, bool buy, vector<int>& prices) {
        int n = prices.size();
        if (idx >= n) return 0;
        if (memo[{idx, buy}]) return memo[{idx, buy}];
        int cool = dp(idx + 1, buy, prices);
        if (buy) {
            int buying = dp(idx + 1, not buy, prices) - prices[idx];
            memo[{idx, buy}] = max(buying, cool);
        } else {
            int sell = dp(idx + 2, true, prices) + prices[idx];
            memo[{idx, buy}] = max(sell, cool);
        }
        return memo[{idx, buy}];
    }
    int maxProfit(vector<int>& prices) {
        return dp(0, true, prices);
    }
};