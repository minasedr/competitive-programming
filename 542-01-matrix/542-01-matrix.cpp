class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        if (n == 0) 
            return mat;
        
        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dir[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        function<bool(int, int)> inbound = [&] (int i, int j){
            return (i >= 0 && i < n && j >= 0 && j < m);
        };
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (auto d: dir) {
                int dr = x + d[0];
                int dc = y + d[1];
                if (inbound(dr,dc) && dist[dr][dc] > dist[x][y] + 1) {
                    dist[dr][dc] = dist[x][y] + 1;
                    q.push({dr, dc});
                }
            }
        }
        return dist;
    }
};