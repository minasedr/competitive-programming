class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        bool ok = true;
        vector<bool>vis(n);
        vector<int> color(n);
        vector<vector<int>> adj(n);
        
        for (int i = 0; i < n; i++)
            adj[i].insert(adj[i].end(), graph[i].begin(), graph[i].end());
        
        function<void(int, int)> dfs;
        dfs = [&](int node, int bip) {
            vis[node] = true;
            color[node] = (bip ? 1: 2);
            for (auto u: adj[node]) {
                if (!vis[u])
                    dfs(u, !bip);
                else if (color[node] == color[u])
                    ok = false;
            }
        };
        
        for (int i = 0; i < n; i++)
            if (!vis[i])
                dfs(i, 1);
        return (ok ? true: false);
    }
};