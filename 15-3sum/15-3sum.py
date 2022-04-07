class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums, ans, n = sorted(nums), set(), len(nums)
        
        for i in range(n):
            if i > 0 and nums[i] == nums[i-1]: continue
            target = -nums[i]
            beg, end = i+1, n-1
            
            while beg < end:
                if nums[beg] + nums[end] < target:
                    beg += 1
                elif nums[beg] + nums[end] > target:
                    end -= 1
                else:
                    ans.add((nums[i],nums[beg],nums[end]))
                    beg, end = beg + 1, end - 1
        return ans