class Solution:
    def hasValidPath(self, grid: List[List[int]]) -> bool:
        ROW = len(grid)
        COL = len(grid[0])
        visited = [[False] * COL for _ in range(ROW)]
        
        directions = {1: [(0,-1),(0,1)], 
                      2: [(-1,0),(1,0)], 
                      3: [(0,-1),(1,0)],  
                      4: [(0,1),(1,0)],  
                      5: [(0,-1),(-1,0)], 
                      6: [(0,1),(-1,0)]}
		
        inbound = lambda row, col: 0 <= row < ROW and 0 <= col < COL
        
        def dfs(row, col):
            if (row, col) == (ROW - 1, COL - 1):
                return True
            visited[row][col] = True
            for dr, dc in directions[grid[row][col]]:
                nr = row + dr
                nc = col + dc
                if not inbound(nr, nc) or visited[nr][nc]:
                    continue
                if (-dr, -dc) in directions[grid[nr][nc]]:
                    if dfs(nr, nc):
                        return True
            return False

        return dfs(0, 0)
