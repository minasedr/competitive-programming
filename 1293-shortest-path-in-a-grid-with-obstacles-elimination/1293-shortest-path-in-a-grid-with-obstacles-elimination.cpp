class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(k + 1)));
        int DIRECTION[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        
        queue<array<int, 4>> Q;
        Q.push({0, 0, grid[0][0], 0});
        visited[0][0][grid[0][0]] = true;
        
        while (!Q.empty()) {
            auto [row, col, obs, dist] = Q.front();
            Q.pop();
            if (row == m - 1 and col == n - 1)
                return dist;
            for (auto DIR: DIRECTION) {
                int nr = row + DIR[0];
                int nc = col + DIR[1];
                if (nr < 0 or nr >= m or nc < 0 or nc >= n)
                    continue;
                if (visited[nr][nc][obs + grid[nr][nc]] or obs + grid[nr][nc] > k)
                    continue;
                Q.push({nr, nc, obs + grid[nr][nc], dist + 1});
                visited[nr][nc][obs + grid[nr][nc]] = true;
            }
        }
        
        return -1;
    }
};