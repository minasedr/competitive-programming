class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<long long>dp(amount + 1, 0);
        dp[0] = 1;
        for (auto c: coins) {
            for (int x = 1; x <= amount; x++) {
                if (x - c >= 0)
                    dp[x] += dp[x - c];
            }
        }
        return dp[amount];
    }
};