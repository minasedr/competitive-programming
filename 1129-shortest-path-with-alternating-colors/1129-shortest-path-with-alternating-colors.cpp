class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, char>>> adj(n);
        
        for (auto e: redEdges)
            adj[e[0]].push_back({e[1], 'R'});
        
        for (auto e: blueEdges)
            adj[e[0]].push_back({e[1], 'B'});
        
        queue<tuple<int, int, char>> Q;
        vector<vector<bool>> vis(n, vector<bool>(2));
        vector<int> ans(n, -1);

        Q.push({0, 0, 'R'});
        Q.push({0, 0, 'B'});
        vis[0][0] = vis[0][1] = true;
        
        while (!Q.empty()) {
            for (int i = 0; i < Q.size(); i++) {
                auto [node, dist, prev] = Q.front();
                Q.pop();
                if (ans[node] == -1)
                    ans[node] = dist;
                else
                    ans[node] = min(ans[node], dist);
                for (auto [cur, col]: adj[node]) {
                    if (vis[cur][col == 'B'] or prev == col)
                        continue;
                    Q.push({cur, dist + 1, col});
                    vis[cur][col == 'B'] = true;
                }
            }
        }
        
        return ans;
    }
};