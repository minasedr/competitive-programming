class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        N = len(prices)
        @cache
        def dfs(i, buying):
            if i >= N: return 0
            cooldown = dfs(i+1, buying)
            if buying:
                buy = dfs(i+1, not buying) - prices[i]
                return max(buy, cooldown)
            else:
                sell = dfs(i+2, True) + prices[i]
                return max(sell, cooldown)
        
        return dfs(0, True)