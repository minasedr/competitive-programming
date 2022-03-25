class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        p = k % len(nums)
        if k:
            nums[:] = nums[-p:] + nums[:-p]