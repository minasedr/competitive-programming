class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adj[n + 1];
        for (auto e: roads) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        
        queue<pair<int, int>> Q;
        Q.push({1, 1e4});
        vector<bool> vis(n + 1);
        vis[1] = true;
        int ans = 1e4;
        bool ok = false;
        
        while (!Q.empty()) {
            auto [node, score] = Q.front();
            Q.pop();
            vis[node] = true;
            ok = (ok or node == n);
            ans = min(ans, score);
            for (auto [u, dist]: adj[node]) {
                if (vis[u]) continue;
                Q.push({u, min(score, dist)});
            }
        }
        return (ok ? ans : -1);
    }
};