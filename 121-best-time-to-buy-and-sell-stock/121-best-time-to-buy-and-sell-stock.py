class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        dp, buy = [0] * len(prices), prices[0]
        
        for i, p in enumerate(prices):
            buy = min(buy, p)
            dp[i] = max(prices[i] - buy, dp[i-1])
        return dp[-1]
