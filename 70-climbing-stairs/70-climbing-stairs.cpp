class Solution {
public:
    unordered_map<int, int> memo;
    int dp(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        if (memo[n])
            return memo[n];
        memo[n] = dp(n - 1) + dp(n - 2);
        return memo[n];
    }
    int climbStairs(int n) {
        return dp(n);
    }
};