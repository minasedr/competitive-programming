class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        nums.sort(reverse=True); n = len(nums) - 2
        
        for i in range(n):
            x, y, z= nums[i:i+3]
            if y+z > x:
                return x+y+z
        return 0