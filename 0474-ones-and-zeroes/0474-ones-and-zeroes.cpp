class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        
        for (int i = 0; i < len; i++) {
            int one = count(strs[i].begin(), strs[i].end(), '1');
            int zero = strs[i].size() - one;
            for (int j = m; j >= zero; j--) {
                for (int k = n; k >= one; k--) {
                    dp[j][k] = max(dp[j][k], 1 + dp[j - zero][k - one]);
                }
            }
        }
        return dp[m][n];
    }
};