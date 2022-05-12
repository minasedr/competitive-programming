class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        
        @cache
        def dp(row, col1, col2):
            if col1 < 0 or col1 >= M or col2 < 0 or col2 >= M:
                return -inf
            result = 0
            result += grid[row][col1]
            if col1 != col2:
                result += grid[row][col2]
                
            if row < N - 1:
                result += max(dp(row + 1, newCol1, newCol2) 
                              for newCol1 in [col1-1, col1, col1+1] 
                              for newCol2 in [col2-1, col2, col2+1])
            return result
        
        N, M = len(grid), len(grid[0])
        return dp(0, 0, M-1)