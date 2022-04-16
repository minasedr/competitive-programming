class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        jobs, n = sorted(list(zip(startTime, endTime, profit))), len(profit)
        @cache
        def dp(i):
            if i >= n: return 0
            l, r , p = jobs[i]
            j = bisect_left(jobs,(r,0,0))
            return max(dp(i+1), dp(j)+p)
        
        return dp(0)