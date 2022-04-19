class Solution:
    def getDescentPeriods(self, prices: List[int]) -> int:
        N, pr = len(prices), prices
        dp = [1] * N
        for i in range(1, N):
            if pr[i] - pr[i-1] == -1:
                dp[i] += dp[i-1]
                
        return sum(dp)
    
        cache = defaultdict(lambda: 1)
        def dp(i):
            if i >= N: return 1
            if pr[i] - pr[i-1] == -1:
                cache[i] = 1 + cache[i-1]
            return cache[i] + dp(i+1)
        
        return dp(1)