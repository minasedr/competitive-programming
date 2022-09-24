class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), [](vector<int>a, vector<int>b) {
            return a[1] < b[1];
        });
        vector<int>dp(n);
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (pairs[i][0] > pairs[j][1])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return 1 + *max_element(dp.begin(), dp.end());
    }
};