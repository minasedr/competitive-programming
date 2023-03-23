class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        vector<int> adj[n + 1];
        vector<bool> vis(n + 1);
        
        function<void(int)> dfs;
        dfs = [&](int node) {
            vis[node] = true;
            for (auto u: adj[node]) {
                if (vis[u])
                    continue;
                dfs(u);
            }
        };
        
        for (auto con: connections) {
            adj[con[0]].push_back(con[1]);
            adj[con[1]].push_back(con[0]);
        }
        
        int components = 0;
        for (int node = 0; node < n; node++) {
            if (not vis[node]) {
                components++;
                dfs(node);
            }
        }
        
        return (m < n - 1 ? -1 : components - 1);
    }
};