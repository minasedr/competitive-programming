class Solution:
    def trap(self, height: List[int]) -> int:
        total = 0
        stack = []
        n = len(height)
        
        for i in range(n):
            while stack and height[stack[-1]] < height[i]:
                curr_height = height[stack.pop()]
                if not stack:
                    break
                bricks = min(height[i], height[stack[-1]]) - curr_height
                total += bricks * (i - stack[-1] - 1)
                
            stack.append(i)
        return total