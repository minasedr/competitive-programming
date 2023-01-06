class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> hasStock(n + 1), noStock(n + 1);
        hasStock[0] = -prices[0];
        
        for (int i = 1; i < n; i++) {
            hasStock[i] = max(hasStock[i - 1], noStock[i - 1] - prices[i]);
            noStock[i] = max(noStock[i - 1], hasStock[i - 1] + prices[i] - fee);
        }
        return noStock[n - 1];
    }
};