class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        n, m, obs = len(obstacleGrid), len(obstacleGrid[0]), obstacleGrid
        @cache
        def dfs(i,j):
            if i >= n or j >= m:
                return 0
            if not obs[i][j] and (i,j) == (n-1, m-1):
                return 1
            if obs[i][j]: return 0
            return dfs(i+1,j) + dfs(i,j+1)
        
        return dfs(0,0)