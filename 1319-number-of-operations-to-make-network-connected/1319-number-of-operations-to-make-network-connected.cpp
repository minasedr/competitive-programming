class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        vector<int> adj[n + 1];
        vector<bool> vis(n + 1);
        
        for (auto con: connections) {
            adj[con[0]].push_back(con[1]);
            adj[con[1]].push_back(con[0]);
        }
        
        queue<int> Q;
        
        int components = 0;
        for (int node = 0; node < n; node++) {
            
            if (not vis[node]) {
                components++;
                Q.push(node);
                vis[node] = true;
                while (!Q.empty()) {
                    auto newNode = Q.front();
                    Q.pop();
                    for (auto u: adj[newNode]) {
                        if (vis[u]) continue;
                        vis[u] = true;
                        Q.push(u);
                    }
                }
            }
        }
        
        return (m < n - 1 ? -1 : components - 1);
    }
};