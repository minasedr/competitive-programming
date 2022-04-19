class Solution:
    def goodDaysToRobBank(self, security: List[int], time: int) -> List[int]:
        N, sec = len(security), security
        dp = [[0,0] for _ in range(N)]
        
        for i in range(N):
            x = N-i-1
            if i > 0 and sec[i] <= sec[i-1]:
                dp[i][0] = 1 + dp[i-1][0]
            if x < N-1 and sec[x+1] >= sec[x]:
                dp[x][1] = dp[x+1][1] + 1
                
        return [i for i in range(N) if (dp[i][0] >= time and dp[i][1] >= time)]