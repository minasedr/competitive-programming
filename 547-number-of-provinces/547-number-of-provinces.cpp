class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool>vis(n, false);
        
        function<void(int)> dfs = [&] (int u) {
            vis[u] = true;
            for (int i = 0; i < n; i++) {
                if (!vis[i] && isConnected[u][i])
                    dfs(i);
            }
        };
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i);
                ans++;
            }
        }
        return ans;
    }
};