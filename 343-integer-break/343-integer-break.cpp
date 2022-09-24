class Solution {
public:
    int dp(int n) {
        if (n < 5) return n;
        return 3 * dp(n - 3);
    }
    int integerBreak(int n) {
        if (n <= 3)
            return n - 1;
        if (n == 4)
            return n;
        return dp(n);
    }
};