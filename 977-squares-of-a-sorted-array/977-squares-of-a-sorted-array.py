class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        ans, n = [0] * len(nums), len(nums) - 1
        l, r = 0, n
        
        while l <= r:
            if abs(nums[l]) > abs(nums[r]):
                ans[n], l = nums[l] ** 2, l + 1
            else:
                ans[n], r = nums[r] ** 2, r - 1
            n -= 1
            
        return ans