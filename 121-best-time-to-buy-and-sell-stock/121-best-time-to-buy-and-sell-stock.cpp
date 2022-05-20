class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        int maxProfit = INT_MIN, buy = prices[0];
        
        for (int i = 0; i < N; i++){
            buy = min(buy, prices[i]);
            maxProfit = max(maxProfit, prices[i] - buy);
        }
        return maxProfit;
    }
};