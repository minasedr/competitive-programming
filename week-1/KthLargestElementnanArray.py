class Solution:
    def kthLargestNumber(self, nums: List[str], k: int) -> str:
        nums = sorted(nums)
        for i in range(len(nums)):
            key = nums[i]
            j = i - 1
            while j >= 0 and len(key) < len(nums[j]):
                nums[j+1] = nums[j]
                j -= 1
            nums[j+1] = key
        return nums[-k]
