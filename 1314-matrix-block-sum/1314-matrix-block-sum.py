class Solution:
    def matrixBlockSum(self, mat: List[List[int]], k: int) -> List[List[int]]:
        n, m, n = (len(mat) * len(mat[0])), len(mat[0]), len(mat)
        ans = [[0]* m for _ in range(n)]
        dp = [[0] * (m+1) for _ in range(n+1)]
        
        
        for i in range(1,n+1):
            for j in range(1,m+1):
                dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + mat[i-1][j-1]
        
        for i in range(1,n+1):
            for j in range(1,m+1):
                a, b = min(i+k,n), min(j+k, m)
                c, d = max(i-k-1,0), max(j-k-1, 0)
                ans[i-1][j-1] = dp[a][b] - (dp[c][b] + dp[a][d]-dp[c][d])
                
        return ans