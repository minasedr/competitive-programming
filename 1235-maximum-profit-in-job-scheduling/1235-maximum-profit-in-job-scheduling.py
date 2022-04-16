class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        work = sorted([(i,j,k) for i,j,k in zip(startTime, endTime, profit)])
        
        @cache
        def dp(i):
            if i >= n: return 0
            l, r , p = work[i]
            j = bisect_left(work,(r,0,0))
            return max(dp(i+1), dp(j)+p)
        
        n = len(work)
        return dp(0)