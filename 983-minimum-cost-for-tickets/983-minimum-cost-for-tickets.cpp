class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        int n = days.back();
        vector<int>dp(n + 1);
        unordered_set<int> st(days.begin(), days.end());
        
        for (int i = 1; i <= n; i++) {
            if (st.count(i))
                dp[i] = min({dp[max(i - 1, 0)] + cost[0],
                             dp[max(i - 7, 0)] + cost[1],
                             dp[max(i - 30, 0)] + cost[2]
                             });
            else
                dp[i] = dp[i - 1];
        }
        return dp[n];
    }
};