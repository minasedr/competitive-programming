class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        ROW, COL = len(grid), len(grid[0])
        directions = [(1, 0), (0, 1), (0, -1), (-1, 0)]
        visited = [[False] * COL for _ in range(ROW)]
        inbound = lambda row, col: 0 <= row < ROW and 0 <= col < COL
        
        ans = 0
        def dfs(row, col):
            nonlocal ans
            visited[row][col] = True
            
            for dr, dc in directions:
                nr = row + dr
                nc = col + dc
                if not inbound(nr, nc) or grid[nr][nc] == 0:
                    ans += 1
                    continue
                if visited[nr][nc]:
                    continue
                dfs(nr, nc)
                
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1 and not visited[i][j]:
                    dfs(i, j)
                    
        return ans