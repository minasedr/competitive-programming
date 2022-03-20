class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        dp, buy, n = [], prices[0], len(prices)
        
        for i in range(n):
            buy = min(buy,prices[i])
            dp.append(prices[i]-buy)

        return max(dp)