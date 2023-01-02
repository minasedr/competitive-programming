class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 1e9);
        dp[0] = 0;
        
        for (int sum = 0; sum <= amount; sum++) {
            for (int i = 1; i <= coins.size(); i++) {
                if (sum >= coins[i - 1])
                    dp[sum] = min(dp[sum], 1 + dp[sum - coins[i - 1]]);
            }
        }
        return (dp[amount] == 1e9 ? -1: dp[amount]);
    }
};