class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        N = len(profit)
        jobs = list(zip(startTime, endTime, profit))
        jobs.sort()
        
        @cache
        def dp(i):
            if i >= N: return 0
            beg, end, profit = jobs[i]
            nextJob = bisect_left(jobs, (end, 0, 0))
            return max(
                dp(i+1),
                dp(nextJob) + profit
            )
        
        return dp(0)