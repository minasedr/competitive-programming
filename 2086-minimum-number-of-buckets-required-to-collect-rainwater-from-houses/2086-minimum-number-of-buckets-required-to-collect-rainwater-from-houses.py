class Solution:
    def minimumBuckets(self, street: str) -> int:
        N, s = len(street), street
        dp, bd = [0] * N, lambda x: 0 < x < N-1
        
        if N == 1 and s[0] == 'H':
            return -1
        for i in range(N):
            if bd(i) and s[i] == 'H':
                if dp[i-1] == 1:
                    continue
                if s[i+1] == '.':
                    dp[i+1] = 1
                elif s[i-1] == '.':
                    dp[i-1] = 1
                else:
                    return -1
            elif i == 0 and s[i] == 'H':
                if s[i+1] == '.':
                    dp[i+1] = 1
                else:
                    return -1
            elif i == N-1 and s[i] == 'H':
                if s[i-1] == '.':
                    dp[i-1] = 1
                else:
                    return -1
        return dp.count(1)