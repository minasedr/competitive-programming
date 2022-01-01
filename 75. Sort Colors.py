class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        high = max(nums)
        count, output = [0] * (high+1), [0] * len(nums)
        for i in nums:
            count[i] += 1
        for j in range(1, len(count)):
            count[j] += count[j-1]
        for k in range(len(nums)-1, -1,-1):
            output[count[nums[k]]-1] = nums[k]
            count[nums[k]] -= 1
        for l in range(len(nums)):
            nums[l] = output[l]
