class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), ans = 0;
        vector<bool>vis(n + 1);
        
        function<void(int)> dfs;
        dfs = [&](int node) {
            vis[node] = true;
            for (int i = 0; i < n; i++) {
                if (isConnected[node][i] && !vis[i])
                    dfs(i);
            }
        };
        
        for (int i = 0; i < n; i++)
            if (!vis[i]) {
                dfs(i);
                ans++;
            }
        return ans;
    }
};