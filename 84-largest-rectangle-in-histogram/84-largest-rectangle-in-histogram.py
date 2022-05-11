class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        maxArea, stack = 0, []
        heights.append(0)
        for idx, height in enumerate(heights):
            start = idx
            while stack and stack[-1][1] > height:
                cur, h = stack.pop()
                maxArea = max(maxArea, h * (idx - cur))
                start = cur
                
            stack.append((start, height))
            
        return maxArea