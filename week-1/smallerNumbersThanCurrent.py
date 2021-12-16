class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        results = []
        for i in nums:
            counter = 0
            for j in range(len(nums)):
                if i > nums[j]:
                    counter += 1
            results.append(counter)
        return results
