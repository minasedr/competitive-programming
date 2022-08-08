class Solution {
public:
    int cnt = 0;
    vector<bool>vis;
    vector<vector<int>>adj;
    
    void dfs(int node, int n) {
        if (node > n)
            return;
        vis[node] = true;
        for (auto u: adj[node]) {
            if (!vis[u])
                dfs(u, n);
        }
        cnt++;
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vis.resize(n, false);
        adj.resize(n);
        for(auto e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for(auto x: restricted)
            vis[x] = true;
        
        dfs(0, n);
        return cnt;
    }
};