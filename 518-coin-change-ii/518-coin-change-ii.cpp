class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount + 1);
        dp[0] = 1;
        
        for (auto c: coins) {
            for (int i = c; i <= amount; i++)
                dp[i] += dp[i - c];
        }
        return dp[amount];
    }
};