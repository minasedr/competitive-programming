class Solution:
    def numEnclaves(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        visited = set()
        indices = [(x,y) for x in range(n) for y in range(m)]
        
        def border(x,y):
            if 0<= x < n and (y == 0 or y == m-1):
                return True
            if 0 <= y < m and (x==0 or x==n-1):
                return True
            return False
        
        def dfs(row, col):
            visited.add((row,col))
            
            for dirs in DIR:
                dx, dy = row + dirs[0], col + dirs[1]
                if (dx,dy) not in visited and inbound(dx,dy) and grid[dx][dy] == 1:
                    dfs(dx,dy)
        
        DIR = [[0,1],[1,0],[-1,0],[0,-1]]
        inbound = lambda x, y: 0 <= x < n and 0 <= y < m
        
        for (x,y) in indices:
            if (x,y) not in visited and inbound(x,y) and border(x,y) and grid[x][y] == 1:
                grid[x][y] = 0
                dfs(x,y)
        tbc = set(indices) - visited
        lands = 0
        for (x,y) in tbc:
            if grid[x][y] == 1:
                lands += 1
                
        return lands