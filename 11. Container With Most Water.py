class Solution:
    def maxArea(self, height: List[int]) -> int:
        i = area = 0
        j = len(height) - 1
        while i < j:
            area = max(area, (j-i) * min(height[i], height[j]))
            # print("area", area)
            if height[i] < height[j]:
                x = i + 1
                while height[i] > height[x] and x < j:
                    x += 1
                i = x
                
            elif height[i] > height[j]:
                x = j - 1
                while x > i and height[x] < height[j] :
                    x -= 1
                j = x
            else:
                i += 1
        return area
