class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        dp = [[1] * i for i in range(1, numRows+1)]

        if numRows > 2:
            for i in range(numRows):
                n = len(dp[i])
                for j in range(n):
                    if j == 0 or j == n-1:
                        continue
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1]
        return dp
    
#         def fact(n):
#             total = 1
#             for i in range(n,0,-1):
#                 total *= i
#             return total
        
#         def comb(n,r):
#             return fact(n)//(fact(n-r)*fact(r))
        
#         for i in range(numRows):
#             for j in range(i+1):
#                 dp[i][j] = comb(i,j)
                
#         return dp