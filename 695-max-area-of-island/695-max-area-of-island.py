class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        n, m, visited, area = len(grid), len(grid[0]), set(), 0
        indices = [(x,y) for x in range(n) for y in range(m)]
        self.ones = 0
        def dfs(row, col):
            self.ones += 1
            visited.add((row,col))
            
            for dirs in DIR:
                dx, dy = row + dirs[0], col + dirs[1]
                if (dx,dy) not in visited and inbound(dx,dy) and grid[dx][dy]:
                    dfs(dx,dy)
        
        DIR = [[0,1],[1,0],[-1,0],[0,-1]]
        inbound = lambda x, y: 0 <= x < n and 0 <= y < m
        for (x,y) in indices:
            if (x,y) not in visited and grid[x][y]:
                dfs(x,y)
                area = max(area, self.ones)
                self.ones = 0
                
        return area