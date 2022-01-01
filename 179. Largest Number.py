class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        if sum(nums) < 1:
            return "0"
        else:
            nums.sort(reverse=True)
            nums = list(map(str, nums))
            for i in range(len(nums)):
                for j in range(i+1, len(nums)):
                    if nums[i] + nums[j] < nums[j] + nums[i]:
                        nums[i], nums[j] = nums[j], nums[i]
        return ''.join(nums)
