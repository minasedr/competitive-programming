class Solution:
    def maxTaxiEarnings(self, n: int, rides: List[List[int]]) -> int:
        def dp(i, memo):
            if i >= n: return 0
            if i in memo: return memo[i]
            l, r, t = rides[i]
            j = bisect_right(rides, [r,0,0])
            memo[i] = max(dp(i+1, memo), dp(j, memo)+(r-l+t))
            return memo[i]
        
        n, rides = len(rides), sorted(rides)
        return dp(0, {})
    