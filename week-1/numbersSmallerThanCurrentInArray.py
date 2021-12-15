class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        output, count = [], 0
        for i in range(len(nums)):
            for j in range(len(nums)):
                if nums[i] > nums[j] and i != j:
                    count += 1
            output.append(count)
            count = 0
        return output
