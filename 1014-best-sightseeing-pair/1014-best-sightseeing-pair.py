class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        dp, grt = 0, (values[0],0)
        
        for i in range(1,len(values)):
            score = (values[i] + grt[0]) + (grt[1]-i)
            dp = max(dp, score)
            if sum(grt) < (values[i] +i):
                grt = (values[i], i)
                
        return dp