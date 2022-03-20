class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        dp = []
        buy = prices[0]
        for i in range(len(prices)):
            buy = min(buy,prices[i])
            dp.append(prices[i]-buy)
        return max(dp)