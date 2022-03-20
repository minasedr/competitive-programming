class Solution:
    def getMaximumGenerated(self, n: int) -> int:
        if not n: return 0
        dp = [0] * (n+1)
        dp[1] = 1
        for i in range(math.ceil(n/2)):
            dp[2*i] = dp[i]
            dp[2*i + 1] = dp[i] + dp[i+1]
        return max(dp)