class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        ans = curr = nums[0]
        N = len(nums)
        
        for i in range(1, N):
            if nums[i] > nums[i-1]:
                curr += nums[i]
            else:
                ans = max(ans, curr)
                curr = nums[i]
                
        return max(ans, curr)