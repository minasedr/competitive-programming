class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp1(n, vector<int>(2, INT_MIN)); // has a stock
        vector<vector<int>> dp2(n, vector<int>(2, INT_MIN)); // has no stock
        
        dp1[0][0] = -prices[0];
        for (int i = 1; i < n; i++) {
            dp1[i][0] = max(dp1[i - 1][0], -prices[i]);
            dp2[i][0] = max(dp2[i - 1][0], dp1[i][0] + prices[i]);
            dp1[i][1] = max(dp1[i - 1][1], dp2[i][0] - prices[i]);
            dp2[i][1] = max(dp2[i - 1][1], dp1[i][1] + prices[i]);
        }
        return max(0, dp2[n - 1][1]);
    }
};
