class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> hasStock(n), noStock(n);
        hasStock[0] = -prices[0];
        
        for (int i = 1; i < n; i++) {
            noStock[i] = max(noStock[i-1], hasStock[i - 1] + prices[i] - fee);
            hasStock[i] = max(hasStock[i-1], noStock[i - 1] - prices[i]);
        }
        return noStock.back();
    }
};