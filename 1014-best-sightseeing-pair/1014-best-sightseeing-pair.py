class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        dp, n, grt = [0] * len(values), len(values), (values[0],0)
        
        for i in range(1,n):
            score = (values[i] + grt[0]) + (grt[1]-i)
            dp[i] = max(dp[i-1], score)
            if sum(grt) < (values[i] +i):
                grt = (values[i], i)
                
        return dp[-1]