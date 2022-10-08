class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int ans = -1, n = edges.size();
        vector<int>dist(n, INT_MAX);
        
        function<void(int, int)> dfs = [&](int u, int x) {
            if (u > -1) {
                if (dist[u] == INT_MAX) {
                    dist[u] = x;
                    dfs(edges[u], x + 1);
                } else if (dist[u] > 0)
                    ans = max(ans, x - dist[u]);
                dist[u] = 0;
            }
        };
        
        for (int i = 0; i < n; i++)
            dfs(i, 1);
        return ans;
    }
};