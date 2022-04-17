class Solution:
    def maxTaxiEarnings(self, n: int, rides: List[List[int]]) -> int:
        def dp(i, memo):
            if i >= N: return 0
            if i in memo:
                return memo[i]
            beg, end, tip = rides[i]
            nextPick = bisect_left(rides,[end,0,0])
            memo[i] = max(
                dp(i+1, memo),
                dp(nextPick, memo) + (end-beg+tip)
            )
            return memo[i]
        N, rides = len(rides), sorted(rides)
        return dp(0, {})
    
   