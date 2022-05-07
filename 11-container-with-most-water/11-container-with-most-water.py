class Solution:
    def maxArea(self, height: List[int]) -> int:
        N, area = len(height), 0
        beg, end = 0, N - 1
        
        while beg < end:
            area = max(area, (min(height[beg], height[end])*(end-beg)))
            if height[beg] < height[end]:
                beg += 1
            else:
                end -= 1
        return area