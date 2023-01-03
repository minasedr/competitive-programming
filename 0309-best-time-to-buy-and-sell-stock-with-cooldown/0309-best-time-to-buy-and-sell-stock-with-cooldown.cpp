class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> hasStock(n), noStock(n), justSold(n);
        hasStock[0] = -prices[0];
        justSold[0] = INT_MIN;
        
        for (int i = 1; i < n; i++) {
            noStock[i] = max(justSold[i - 1], noStock[i - 1]);
            hasStock[i] = max(hasStock[i - 1], noStock[i - 1] - prices[i]);
            justSold[i] = max(hasStock[i - 1] + prices[i], justSold[i - 1]);
        }
        return max(noStock[n - 1], justSold[n - 1]);
    }
};