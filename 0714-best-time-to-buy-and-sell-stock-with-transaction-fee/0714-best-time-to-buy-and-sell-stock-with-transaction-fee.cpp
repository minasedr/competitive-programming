class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int hasStock = -prices[0], noStock = 0;
        
        for (int i = 1; i < prices.size(); i++) {
            hasStock = max(hasStock, noStock - prices[i]);
            noStock = max(noStock, hasStock + prices[i] - fee);
        }
        return noStock;
    }
};