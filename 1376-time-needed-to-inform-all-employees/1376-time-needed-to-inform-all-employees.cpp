class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < n; i++)
            if (manager[i] != -1)
                adj[manager[i]].push_back(i);
        
        function<int()> bfs;
        bfs = [&]() {
            queue<array<int, 2>> Q;
            vector<bool>vis(n);
            Q.push({headID, informTime[headID]});
            vis[headID] = true;
            int time = 0;
            while (!Q.empty()) {
                int M = Q.size();
                for (int i = 0; i < M; i++) {
                    auto [id, t] = Q.front();
                    Q.pop();
                    time = max(time, t);
                    for (auto u: adj[id]) {
                        if (vis[u])
                            continue;
                        Q.push({u, t + informTime[u]});
                        vis[u] = true;
                    }
                }
                
            }
            return time;
        };
        return bfs();
    }
};