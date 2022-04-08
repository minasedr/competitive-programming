class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        dp = [0] * len(cost)
        
        for i in range(len(cost)):
            dp[i] = cost[i] + min(dp[i-1], dp[i-2])
            
        return min(dp[-1], dp[-2])
