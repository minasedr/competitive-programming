class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        time, n, total = timeSeries, len(timeSeries), 0
        
        for i in range(n-1):
            total += min(time[i+1] - time[i], duration)
         
        return total + duration