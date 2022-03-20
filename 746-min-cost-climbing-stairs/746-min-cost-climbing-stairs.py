class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        dp = [0] * (len(cost) + 1)
        pay = lambda x: dp[x-1] + cost[x-1]
        
        for i in range(len(cost)+1):
            if i > 1:
                dp[i] = min(pay(i), pay(i-1))
                
        return dp[-1]