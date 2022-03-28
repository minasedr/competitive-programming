class Solution:
    def subArrayRanges(self, nums: List[int]) -> int:
        n, total = len(nums), 0
        
        for i in range(n):
            large = small = nums[i]
            for j in range(i+1, n):
                large = max(large, nums[j])
                small = min(small, nums[j])
                total += large - small
                
        return total