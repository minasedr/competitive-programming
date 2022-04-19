class Solution:
    def getDescentPeriods(self, prices: List[int]) -> int:
        cache = defaultdict(lambda: 1)
        N, pr = len(prices), prices
        
        def dfs(i):
            if i >= N: return 1
            cache[i] = 1 + cache[i-1] if pr[i] - pr[i-1] == -1 else cache[i]
            return cache[i] + dfs(i+1)
        
        return dfs(1)