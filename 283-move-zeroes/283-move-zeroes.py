class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        l = 0
        for r in range(len(nums)):
            if nums[r]:
                nums[r], nums[l], l = nums[l], nums[r], l + 1
        return
    
        l, r = 0, 0
        while r < len(nums):
            if nums[r]:
                nums[l], nums[r], l = nums[r], nums[l], l + 1
            r += 1