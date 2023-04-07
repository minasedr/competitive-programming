class Solution:
    def hasValidPath(self, grid: List[List[int]]) -> bool:
        destination = (len(grid)-1, len(grid[0]) - 1)
        
        directions = {1: [(0,-1),(0,1)], 
                      2: [(-1,0),(1,0)], 
                      3: [(0,-1),(1,0)],  
                      4: [(0,1),(1,0)],  
                      5: [(0,-1),(-1,0)], 
                      6: [(0,1),(-1,0)]}
		
        inbound = lambda row, col: 0 <= row < len(grid) and 0 <= col < len(grid[0])
		
        visited = set([(0, 0)])

        def dfs(row, col):
            if (row, col) == destination:
                return True
            visited.add((row, col))
            for dr, dc in directions[grid[row][col]]:
                nr = row + dr
                nc = col + dc
                
                if not inbound(nr, nc) or (nr, nc) in visited:
                    continue
                if (-dr, -dc) in directions[grid[nr][nc]]:
                    if dfs(nr, nc):
                        return True
            return False

        return dfs(0, 0)
