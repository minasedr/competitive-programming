class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount + 1, 1e9);
        dp[0] = 0;
        for (int x = 1; x <= amount; x++) {
            for (auto c: coins) {
                if (x - c >= 0)
                    dp[x] = min(dp[x], dp[x-c] + 1);
            }
        }
        return (dp[amount] == 1e9 ? -1: dp[amount]);
    }
};