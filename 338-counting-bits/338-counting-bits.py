class Solution:
    def countBits(self, n: int) -> List[int]:
        dp = [0 for i in range(n+1)]
        
        for i in range(len(dp)):
            if i <= 1:
                dp[i] = i
            elif i % 2 == 0:
                dp[i] = dp[i//2]
            else:
                dp[i] = dp[i//2] + 1
        
        return dp