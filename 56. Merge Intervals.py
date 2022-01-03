class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        merged = [intervals[0]]
        if len(intervals) <= 1:
            return intervals
        else:
            for i in range(1,len(intervals)):
                if merged[-1][1] >= intervals[i][0]:
                    if merged[-1][1] < intervals[i][1]:
                        merged[-1][1] = intervals[i][1]
                else:
                    merged.append(intervals[i])
        return merged
