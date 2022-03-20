class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        dp = [[1] * i for i in range(1,rowIndex+2)]
        
        if rowIndex > 1:
            for i in range(len(dp)):
                n = len(dp[i])
                for j in range(n):
                    if j == 0 or j == n-1:
                        continue
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1]
        return dp[rowIndex]