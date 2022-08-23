class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size(), ans = 0;
        vector<vector<int>> v;
        vector<int> dp(n);
        
        for (int i = 0; i < n; i++)
            v.push_back({ages[i], scores[i]});
        sort(v.begin(), v.end());
        
        for (int i = 0; i < n; i++) {
            dp[i] = v[i][1];
            for (int j = 0; j < i; j++) {
                if (v[i][1] >= v[j][1])
                    dp[i] = max(dp[i], dp[j] + v[i][1]);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};