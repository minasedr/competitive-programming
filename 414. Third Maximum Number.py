class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        nums.sort()
        count = 0
        if len(Counter(nums)) < 3:
            return max(nums)
        else:
            for i in range(len(nums)-1, -1, -1):
                if nums[i] != nums[i-1]:
                    count += 1
                    if count == 3:
                        return nums[i]
