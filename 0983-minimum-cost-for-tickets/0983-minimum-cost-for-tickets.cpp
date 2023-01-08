class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int cnt[]{1,7, 30};
        vector<int> dp(n + 1, -1);
        
        function<int(int)> dfs;
        dfs = [&](int i) {
            if (i >= n) return 0;
            if (dp[i] != -1) 
                return dp[i];
            int cost = 1e6;
            for (int j = 0; j < 3; j++) {
                int nxt = lower_bound(days.begin(), days.end(), days[i] + cnt[j]) - days.begin();
                for (int k = i + 1; k <= nxt; k++)
                    cost = min(cost, costs[j] + dfs(k));
            }
            return dp[i] = cost;
        };
        
        return dfs(0);
    }
};