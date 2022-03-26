class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        dp, n, m = [0] * len(prices), len(prices), prices[0]
        
        for i in range(1,n):
            m = min(m, prices[i])
            if prices[i] > prices[i-1]:
                dp[i] = dp[i-1] + (prices[i] - prices[i-1])
            else:
                dp[i] = max((prices[i] - m), dp[i-1])
                
        return dp[-1]