class Solution {
public:
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> ans, indeg(n);
        map<int, set<int>> adj;
        
        for (auto pr: prerequisites) {
            adj[pr[1]].insert(pr[0]);
            indeg[pr[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (indeg[i] == 0)
                q.push(i);
        
        while (!q.empty()) {
            int u = q.front();
            ans.push_back(u);
            q.pop();
            for (auto v: adj[u])
                if (--indeg[v] == 0)
                    q.push(v);
        }
        if (ans.size() == n)
            return ans;
        else
            return {};
    }
};