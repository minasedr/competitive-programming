class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        total = max_value = sum(nums[:k])

        for i in range(k, len(nums)):
            total += nums[i] - nums[i-k]
            max_value = max(max_value, total)

        return max_value/k