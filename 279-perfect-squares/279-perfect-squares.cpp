class Solution {
public:
    int numSquares(int n) {
        vector<int> sq;
        for (int i = 1; i * i <= n; i++)
            sq.push_back(i*i);
        vector<int> dp(n + 1, 1e9);
        dp[0] = 0;
        for (int x = 1; x <= n; x++) {
            for (auto c: sq) {
                if (x - c >= 0)
                    dp[x] = min(dp[x], dp[x-c] + 1);
            }
        }
        return dp[n];
    }
};