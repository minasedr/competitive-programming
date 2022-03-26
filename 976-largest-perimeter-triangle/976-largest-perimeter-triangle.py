class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        per, nums = 0, sorted(nums, reverse=True)
        
        def perimeter(x,y,z):
            if nums[z] + nums[y] > nums[x]: #since sorted, this if is enough
                return nums[z]+nums[y]+nums[x]
            return 0
        
        for i in range(len(nums)-2):
            per = max(per, perimeter(i,i+1,i+2))
                    
        return per