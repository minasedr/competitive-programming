class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = numCourses;
        vector<vector<bool>>dist(n, vector<bool>(n));
        for (auto pr: prerequisites)
            dist[pr[0]][pr[1]] = true;
        
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j] = dist[i][j] || (dist[i][k] && dist[k][j]);
                }
            }
        }
        vector<bool> ans;
        for (auto q: queries)
            ans.push_back(dist[q[0]][q[1]]);
        
        return ans;
    }
};