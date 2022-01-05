class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        count = Counter(nums)
        demo = []
        for i in range(len(nums)):
            if count[nums[i]] > 0:
                demo.append(nums[i])
                count[nums[i]] = 0
        nums[:] = demo[:]
        return len(demo)
