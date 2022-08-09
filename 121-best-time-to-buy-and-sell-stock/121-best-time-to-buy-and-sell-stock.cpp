class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0], n = prices.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            buy = min(buy, prices[i]);
            ans = max(ans, prices[i] - buy);
        }
        return ans;
    }
};