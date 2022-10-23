class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> hasStock(n, vector<int>(2, INT_MIN));
        vector<vector<int>> noStock(n, vector<int>(2, INT_MIN));
        
        hasStock[0][0] = -prices[0];
        for (int i = 1; i < n; i++) {
            hasStock[i][0] = max(hasStock[i - 1][0], -prices[i]);
            noStock[i][0] = max(noStock[i - 1][0], hasStock[i][0] + prices[i]);
            hasStock[i][1] = max(hasStock[i - 1][1], noStock[i][0] - prices[i]);
            noStock[i][1] = max(noStock[i - 1][1], hasStock[i][1] + prices[i]);
        }
        return max(0, noStock[n - 1][1]);
    }
};
