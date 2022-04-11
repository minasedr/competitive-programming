class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        dp, n = {}, len(prices)
        
        def dfs(i, buying):
            if i >= n: return 0
            if (i, buying) in dp:
                return dp[(i,buying)]
            
            if buying:
                dp[(i,buying)] = max(dfs(i+1, False)-prices[i], dfs(i+1, True))
            else:
                dp[(i,buying)] = max(dfs(i+2, True)+prices[i], dfs(i+1, buying))
            return dp[(i,buying)]
        
        return dfs(0, True)
