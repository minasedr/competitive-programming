class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        maxArea, stack = 0, []
        
        for idx, height in enumerate(heights):
            start = idx
            while stack and stack[-1][1] > height:
                cur, h = stack.pop()
                maxArea = max(maxArea, h * (idx - cur))
                start = cur
                
            stack.append((start, height))
            
        for i, h in stack:
            maxArea = max(maxArea, h * (len(heights) - i))
        return maxArea