class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int dir[][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        
        queue<tuple<int, int, int>> Q;
        vector<vector<bool>> visited(n, vector<bool>(n));
        Q.push({0, 0, 1});
        visited[0][0] = true;
        if (grid[0][0]) return -1;
        
        while (!Q.empty()) {
            auto [r, c, dist] = Q.front();
            Q.pop();
            if (r == n - 1 and c == n - 1)
                return dist;
            for (auto d: dir) {
                int nr = r + d[0];
                int nc = c + d[1];
                if (nr < 0 or nr >= n or nc < 0 or nc >= n or visited[nr][nc] or grid[nr][nc] == 1)
                    continue;
                Q.push({nr, nc, dist + 1});
                visited[nr][nc] = true;
            }
        }
        return -1;
    }
};