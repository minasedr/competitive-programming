class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        nums.sort()
        results = []
        nums = set(nums)
        if len(nums)<= 2:
            return max(nums)
        else:
            for x in nums:
                results.append(x)
            results.sort()
            return results[-3]
