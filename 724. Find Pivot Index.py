class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        aggr = sum(nums)
        prefix = 0
        for i in range(len(nums)):
            if prefix == aggr - prefix - nums[i]:
                return i
            prefix += nums[i]
        return -1
