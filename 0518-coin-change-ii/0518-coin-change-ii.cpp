class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount + 1);
        dp[0] = 1;
        
        for (int i = 1; i <= n; i++)
            for (int sum = 1; sum <= amount; sum++)
                if (sum >= coins[i - 1])
                    dp[sum] += dp[sum - coins[i - 1]];
        
        return dp[amount];
    }
};