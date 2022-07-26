class Solution {
public:
    vector<int>visited;
    map<int,vector<int>>adj;
    
    bool dfs(int v) {
        if (visited[v] == 1)
        return false;
        if (visited[v] == 2)
            return true;
        visited[v] = 1;
        for (auto u: adj[v]) {
            if (!dfs(u))
                return false;
        }
        visited[v] = 2;
        return true;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        visited.assign(numCourses, false);
        for (auto p: prerequisites)
            adj[p[1]].push_back(p[0]);
        
        for (int i = 0; i < numCourses; i++)
            if (!dfs(i))
                return false;
        return true;
    }
};