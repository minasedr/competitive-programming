class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        l, r, n = 0, 1, len(nums)
        
        while r < n:
            while l < n and nums[l]:
                l += 1
            r = l if r < l else r
            while r < n and not nums[r]:
                r += 1
            if l < n and r < n:
                nums[l], nums[r] = nums[r], 0