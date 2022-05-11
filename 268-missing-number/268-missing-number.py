class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        N = len(nums)
        tot = (N+1)*(N)//2
        return tot - sum(nums)