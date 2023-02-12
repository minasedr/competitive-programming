class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int n = routes.size();
        unordered_map<int, vector<int>> adj;
        
        for (int i = 0; i < n; i++)
            for (int j : routes[i])
                adj[j].push_back(i);
        
        queue<pair<int, int>> Q;
        unordered_set<int> vis{source};
        Q.push({source, 0});
        
        while (!Q.empty()) {
            auto [stop, bus] = Q.front();
            Q.pop();
            if (stop == target)
                return bus;
            for (auto u: adj[stop]) {
                for (int v: routes[u]) {
                    if (vis.count(v))
                        continue;
                    vis.insert(v);
                    Q.push({v, bus + 1});
                }
                routes[u].clear();
            }
        }
        return -1;
    }
};