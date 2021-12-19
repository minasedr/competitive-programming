class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        nums.sort()
        #for j in range(len(nums)):
        for i in range(1,len(nums)-1):
            if nums[i-1] <= nums[i] and nums[i] <= nums[i+1]:
                nums[i], nums[i+1] = nums[i+1], nums[i]
            elif nums[i-1] > nums[i] and nums[i+1] < nums[i]:
                nums[i+1], nums[i] = nums[i],nums[i+1]
                    
        return nums
