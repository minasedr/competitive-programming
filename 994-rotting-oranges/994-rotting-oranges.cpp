class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        pair<int,int>dir[] = {{1,0}, {0,1}, {-1, 0}, {0,-1}};
        queue<pair<int,int>>q;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2)
                    q.push({i,j});
            }
        }
        
        if (q.empty()) {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    if (grid[i][j] == 1)
                        return -1;
            return 0;
        }
        
        auto valid = [&](int x,int y) {
          return (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 1);  
        };
        
        int cnt = 0;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                auto u = q.front();
                q.pop();
                grid[u.first][u.second] = 2;
                for (auto [x,y]: dir) {
                    int dx = u.first + x;
                    int dy = u.second + y;
                    if (valid(dx,dy)) {
                        q.push({dx,dy});
                        grid[dx][dy] = 2;
                    }
                }
            }
            cnt++;
        }
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1)
                    return -1;
        return cnt - 1;
    }
};