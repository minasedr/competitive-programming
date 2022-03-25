class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        n, m, islands = len(grid), len(grid[0]), 0
        is_boundary = lambda i,j: (i == 0 or i == n-1 or j == 0 or j == m-1)
        indices = [(i,j) for i in range(n) for j in range(m)]
        
        def dfs(i, j):
            if grid[i][j] == 1: return True
            
            valid = not is_boundary(i,j)
            grid[i][j] = 1
            
            up, down, left, right = True,True,True,True
            if i > 0: up = dfs(i-1,j)
            if i < n-1: down = dfs(i+1,j)
            if j > 0: left = dfs(i,j-1)
            if j < m-1: right = dfs(i,j+1)
                
            return valid and up and down and left and right
        
        for i, j in indices:
            if grid[i][j] == 0:
                if dfs(i,j): islands += 1
                        
        return islands