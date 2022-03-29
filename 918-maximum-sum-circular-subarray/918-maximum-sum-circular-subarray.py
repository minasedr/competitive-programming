class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        if max(nums) < 0: return max(nums)

        min_el = max_el = dp_max = dp_min = nums[0]

        for i in range(1, len(nums)):
            dp_max = max(nums[i], dp_max+nums[i])
            max_el = max(max_el, dp_max)
            
            dp_min = min(nums[i], dp_min+nums[i])
            min_el = min(min_el, dp_min)
            
        return max(sum(nums)-min_el, max_el)