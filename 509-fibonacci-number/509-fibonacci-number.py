class Solution:
    def fib(self, n: int, memo={}) -> int:
        dp = [0,1]
        
        for i in range(n):
            dp[-1], dp[-2] = dp[-1] + dp[-2], dp[-1]

        return dp[0]