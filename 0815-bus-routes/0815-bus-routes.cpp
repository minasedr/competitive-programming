class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int n = routes.size();
        map<int, vector<int>> adj;
        
        for (int i = 0; i < n; i++)
            for (int j : routes[i])
                adj[j].push_back(i);
        
        queue<array<int, 2>> Q;
        Q.push({source, 0});
        set<int> vis = {source};
        
        while (!Q.empty()) {
            auto [dest, bus] = Q.front();
            Q.pop();
            if (dest == target)
                return bus;
            for (int u: adj[dest]) {
                for (int v: routes[u]) {
                    if (vis.count(v))
                        continue;
                    Q.push({v, bus + 1});
                    vis.insert(v);
                }
                routes[u].clear();
            }
        }
        return -1;
    }
};