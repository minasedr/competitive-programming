class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<int> deg(n);
        
        for (auto e: prerequisites) {
            adj[e[1]].push_back(e[0]);
            deg[e[0]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (deg[i] == 0)
                q.push(i);
        
        vector<int> ans;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (auto u: adj[node]) {
                if (--deg[u] == 0)
                    q.push(u);
            }
        }
        if (ans.size() == n)
            return ans;
        return {};
    }
};