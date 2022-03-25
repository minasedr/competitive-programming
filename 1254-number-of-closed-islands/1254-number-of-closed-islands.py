class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        n , m, visited, total = len(grid), len(grid[0]), set(), 0
        indices = [(i,j) for i in range(n) for j in range(m)]
        
        def dfs(row, col, flag):
            visited.add((row,col))
            grid[row][col] = flag

            for d in DIR:
                dx, dy = row + d[0], col + d[1]
                if (dx,dy) not in visited and inbound(dx,dy) and grid[dx][dy] == 0:
                    dfs(dx,dy, flag)
            return 1
        
        def boundary(x,y):
            if x == n - 1 or y == m - 1:
                return True
            if x == 0 or y == 0:
                return True
        
        DIR = [[0,1],[1,0],[-1,0],[0,-1]]
        inbound = lambda x,y: 0<=x<n and 0<=y<m
        
        for x,y in indices:
            if boundary(x,y) and grid[x][y] == 0:
                dfs(x,y,1)
                
        for a,b in indices:
            if (a,b) not in visited and grid[a][b] == 0:
                total += dfs(a,b,0)
                
        return total
                