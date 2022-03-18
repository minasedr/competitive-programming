class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        n, m = len(grid), len(grid[0])
        indices = [(x,y) for x in range(n) for y in range(m)]
        
        def dfs(row, col):
            visited.add((row,col))
            
            for d in DIR:
                dx, dy = row + d[0], col + d[1]
                if inbound(dx,dy) and (dx,dy) not in visited and grid[dx][dy] == "1":
                    dfs(dx,dy)
                    
        DIR = [[0,1],[1,0],[-1,0],[0,-1]]
        inbound = lambda x,y: 0<=x<n and 0<=y<m
        visited, counter = set(), 0
        for x,y in indices:
            if  (x,y) not in visited and grid[x][y] == "1":
                counter += 1
                dfs(x,y)
                
        return counter