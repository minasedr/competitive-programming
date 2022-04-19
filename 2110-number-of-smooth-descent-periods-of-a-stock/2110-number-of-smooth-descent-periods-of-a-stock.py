class Solution:
    def getDescentPeriods(self, prices: List[int]) -> int:
        cache = defaultdict(lambda: 1)
        N, pr = len(prices), prices
        
        def dp(i):
            if i >= N: return 1
            if pr[i] - pr[i-1] == -1:
                cache[i] = 1 + cache[i-1]
            return cache[i] + dp(i+1)
        
        return dp(1)