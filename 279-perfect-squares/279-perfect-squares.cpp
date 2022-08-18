class Solution {
public:
    unordered_map<int,int> memo;
    int numSquares(int n) {
        if (n == 0) return 0;
        if (memo[n]) return memo[n];
        int ans = INT_MAX;
        for (int i = 1; i * i <= n; i++)
            ans = min(ans, 1 + numSquares(n - (i * i)));
        memo[n] = ans;
        return ans;
    }
};
