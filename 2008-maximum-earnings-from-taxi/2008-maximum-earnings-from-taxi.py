class Solution:
    def maxTaxiEarnings(self, n: int, rides: List[List[int]]) -> int:
        @cache
        def dp(i):
            if i >= n: return 0
            l, r, t = rides[i]
            j = bisect_right(rides, [r,0,0])
            return max(dp(i+1), dp(j)+(r-l+t))
        
        n, rides = len(rides), sorted(rides)
        return dp(0)