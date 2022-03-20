class Solution:
    def divisorGame(self, n: int) -> bool:
        dp = [False] * (n)
        for i in range(1,n):
            dp[i] = True if dp[i-1] == False else False
        return dp[-1]