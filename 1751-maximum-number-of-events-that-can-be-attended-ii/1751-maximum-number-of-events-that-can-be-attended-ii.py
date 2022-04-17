class Solution:
    def maxValue(self, events: List[List[int]], k: int) -> int:
        @cache
        def dp(i, rem):
            if not rem or i >= N: return 0
            beg, end, value = events[i]
            nextEvent = bisect_left(events, [end+1,0,0])
            return max(
                dp(i+1, rem),
                dp(nextEvent, rem-1) + value
            )
        N = len(events)
        events.sort()
        return dp(0, k)