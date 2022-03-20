class Solution:
    def tribonacci(self, n: int) -> int:
        dp = [0,1,1]
        
        for i in range(n):
            dp[-3], dp[-2], dp[-1] = dp[-2], dp[-1], dp[-1] + dp[-2] + dp[-3]
        return dp[0]