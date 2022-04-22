class Solution:
    def minimumBuckets(self, street: str) -> int:
        N, s = len(street), street
        dp, bd = [0] * N, lambda x: 0 < x < N-1
        f = lambda x: s[x] == 'H'
        
        if N == 1 and f(0):
            return -1
        
        for i in range(N):
            if bd(i) and f(i):
                if dp[i-1] == 1: continue
                if not f(i+1): dp[i+1] = 1
                elif not f(i-1): dp[i-1] = 1
                else: return -1
                
            elif i == 0 and f(i):
                if not f(i+1): dp[i+1] = 1
                else: return -1
                
            elif i == N-1 and f(i):
                if not f(i-1): dp[i-1] = 1
                else: return -1
                
        return dp.count(1)