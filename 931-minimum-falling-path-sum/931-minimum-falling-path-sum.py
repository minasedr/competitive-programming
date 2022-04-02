class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        n, m = len(matrix), len(matrix[0])
        dp = [[0] * m for _ in range(n)]
        
        for i in range(n):
            for j in range(m):
                if i == 0:
                    dp[i][j] = matrix[i][j]
                    continue
                second = dp[i-1][j-1] if j > 0 else math.inf
                third = dp[i-1][j+1] if j < m-1 else math.inf
                dp[i][j] = matrix[i][j] + min(dp[i-1][j],second, third)
                
        return min(dp[-1])