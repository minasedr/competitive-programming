class Solution:
    def fib(self, n: int, memo={}) -> int:
        dp = [0,1]
        
        for i in range(1,n):
            dp[-1], dp[-2] = dp[-1] + dp[-2], dp[-1]

        return dp[0] if n == 0 else dp[-1]