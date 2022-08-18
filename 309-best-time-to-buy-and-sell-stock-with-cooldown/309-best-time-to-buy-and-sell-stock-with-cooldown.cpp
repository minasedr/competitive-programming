class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> hasStock(n), noStock(n), justSold(n);
        hasStock[0] = -prices[0];
        justSold[0] = INT_MIN;
        for (int i = 1; i < n; i++) {
            noStock[i] = max(noStock[i - 1], justSold[i - 1]);
            hasStock[i] = max(noStock[i-1] - prices[i], hasStock[i - 1]);
            justSold[i] = hasStock[i-1] + prices[i];
        }
        return max(noStock.back(), justSold.back());
    }
};