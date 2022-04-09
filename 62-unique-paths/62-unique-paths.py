class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        cache = {}
        def dfs(i,j):
            if (i,j) in cache:
                return cache[(i,j)]
            if i >= m or j >= n:
                return 0
            if (i,j) == (m-1,n-1):
                return 1
            down, left = dfs(i+1,j), dfs(i,j+1)
            cache[(i,j)] = down + left
            return cache[(i,j)]
        
        return dfs(0,0)