class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> hasStock(n, vector<int>(k + 1, INT_MIN));
        vector<vector<int>> noStock(n, vector<int>(k + 1, INT_MIN));
        
        hasStock[0][0] = -prices[0];
        for (int i = 1; i < n; i++) {
            hasStock[i][0] = max(hasStock[i - 1][0], -prices[i]);
            noStock[i][0] = max(noStock[i - 1][0], hasStock[i][0] + prices[i]);

            for (int j = 1; j < k; j++) {
                hasStock[i][j] = max(hasStock[i - 1][j], noStock[i][j - 1] - prices[i]);
                noStock[i][j] = max(noStock[i - 1][j], hasStock[i][j] + prices[i]);
            }
        }
        
        return max(0, noStock[n - 1][k - 1]);
    }
};