class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1);
        
        for (int i = 0; i <= n; i++) {
            int cur = 0, large = 0;
            for (int j = 1; j <= k && i >= j; j++) {
                cur = max(cur, arr[i - j]);
                large = max(large, dp[i - j] + cur * j);
            }
            dp[i] = large;
        }
        return dp[n];
    }
};